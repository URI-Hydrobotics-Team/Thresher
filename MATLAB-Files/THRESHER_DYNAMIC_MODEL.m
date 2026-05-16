%% THRESHER SYSTEM MODEL %%

% This Model is an adaptation of T. Fossen's model of the Remus 100 AUV
% It's been Modified to reflect the properties of "Thresher".
%
% Control parameters for a pitch-heave and sway-yaw system are calculated
%
% References: 
%   B. Allen, W. S. Vorus and T. Prestero, "Propulsion system 
%       performance enhancements on REMUS AUVs," OCEANS 2000 MTS/IEEE 
%       Conference and Exhibition. Conference Proceedings, 2000, 
%       pp. 1869-1873 vol.3, doi: 10.1109/OCEANS.2000.882209.
%   T. I. Fossen (2021). Handbook of Marine Craft Hydrodynamics and
%       Motion Control. 2nd. Edition, Wiley. URL: www.fossen.biz/wiley   
%   R. J. Vaccaro

%% REMUS GEO
L_nom = 1.60;    % [m]
D_nom = 0.19;    % [m]

%% SCALE
L_scale = 1.0;   % 1.0 = nominal REMUS-class length
D_scale = 1.0;   % 1.0 = nominal REMUS-class diameter

L = L_nom * L_scale;
D = D_nom * D_scale;

%% INERTIA (scales: m ~ L*D^2,  I ~ m*L^2)
m_nom  = 35.0;          % [kg]
Iyd_nom = 3.45;         % nominal pitch/yaw MOI [kg*m^2] (equal for circular x-section)
m   = m_nom  * L_scale * D_scale^2;
I_y = Iyd_nom * L_scale^3 * D_scale^2;   % pitch MOI [kg*m^2]
I_z = Iyd_nom * L_scale^3 * D_scale^2;   % yaw   MOI [kg*m^2]

%% CG / CB POSITIONS (from geometric hull centre)
x_g =  -0.010 * L_scale;   % CG: slightly aft of centre [m]
z_g =   0.005 * D_scale;   % CG: slightly below centreline [m]  (z-down, +ve = below)
x_b =   0.000;             % CB: at geometric centre [m]
z_b =  -0.010 * D_scale;   % CB: slightly above centreline [m]  (z-down, -ve = above)

%% AFT CONTROL SURFACES
x_ctrl  = -0.45 * L;                            % control surface x-position [m] (< 0)
S_ctrl  =  0.0150 * (L/L_nom) * (D/D_nom);     % planform area [m^2], scales with L,D
a_w     =  3.8;                                 % lift-curve slope [1/rad]

%% OPERATING CONDITION
U   = 1.5;      % forward speed [m/s]
rho = 1030;   % water density [kg/m^3]
g   =  9.81;    % gravitational acceleration [m/s^2]

%%  BUILD PARAMETER STRUCTS
%  (pitch-heave needs z_g, z_b; sway-yaw does not)
ph          = struct();   % pitch-heave parameters
ph.L        = L; 
ph.D       = D;
ph.m        = m;   
ph.I_y     = I_y;
ph.x_g      = x_g; 
ph.z_g    = z_g;
ph.x_b      = x_b;  
ph.z_b    = z_b;
ph.x_planes = x_ctrl;
ph.S_planes = S_ctrl;
ph.a_w      = a_w;
ph.U        = U;  
ph.rho = rho;  
ph.g = g;

sy          = struct();   % sway-yaw parameters
sy.L        = L;    
sy.D        = D;
sy.m        = m;    
sy.I_z      = I_z;
sy.x_g      = x_g;  
sy.y_g     = 0.0;
sy.x_b      = x_b;
sy.x_rudder = x_ctrl;
sy.S_rudder = S_ctrl;
sy.a_w      = a_w;
sy.U        = U;   
sy.rho = rho;   
sy.g = g;

%  RUN BOTH MODELS
fprintf('\n');
[M_ph, N_ph, B_ph, A_ph, Bsys_ph, r_ph] = pitch_heave_matrices(ph);
fprintf('\n\n');
[M_sy, N_sy, B_sy, A_sy, Bsys_sy, r_sy] = sway_yaw_matrices(sy);

%%  PITCH-HEAVE MODEL
%
%  STATE:   x = [w, q, theta]'
%             w     — heave velocity [m/s]  (+ve = sinking, z-down)
%             q     — pitch rate    [rad/s] (+ve = bow-up)
%             theta — pitch angle   [rad]   (+ve = bow-up)
%
%  DYNAMICS:  M * [wdot; qdot] = N * [w; q; theta] + B * delta
%             thetadot = q                                (kinematics)
%
%  CONTROL:  delta [rad] — stern plane deflection
%            Positive delta => trailing-edge down => bow-up pitch moment
%
function [M, N, B, A_sys, B_sys, r] = pitch_heave_matrices(p)
% pitch_heave_matrices  Build M (2x2), N (2x3), B (2x1) for vertical-plane model.
%
%   Inputs:
%     p — parameter struct with fields:
%           L, D          hull length and diameter [m]
%           m, I_y        mass [kg], pitch MOI [kg*m^2]
%           x_g, z_g      CG position from hull centre [m] (z-down)
%           x_b, z_b      CB position from hull centre [m] (z-down)
%           x_planes      aft plane x-position [m]  (< 0)
%           S_planes      aft plane planform area [m^2]
%           a_w           lift-curve slope [1/rad]
%           U             forward speed [m/s]
%           rho, g        fluid density [kg/m^3], gravity [m/s^2]
%
%   Outputs:
%     M      2x2 generalised mass matrix
%     N      2x3 generalised forcing matrix  (cols: w, q, theta)
%     B      2x1 control input matrix        (stern plane delta)
%     A_sys  3x3 full state-space A matrix   (x = [w,q,theta]')
%     B_sys  3x1 full state-space B vector
%     r      struct of all intermediate hydrodynamic quantities

    r_hull = p.D / 2;

    Vol   = pi * r_hull^2 * p.L;
    Bfrc  = p.rho * p.g * Vol;          % buoyancy force [N]
    W     = p.m   * p.g;                % weight         [N]

    % ── ADDED MASS (Lamb's prolate-spheroid coefficients) ─────────────────────
    [m11, m22, k1] = lamb_added_mass(p.L, p.D, p.rho, Vol);

    % SNAME derivatives (negative by convention — added mass opposes acceleration)
    Z_wdot = -m22;                                          % [kg]
    M_qdot = -p.rho * pi * r_hull^2 * p.L^3 / 12.0;       % [kg*m^2]
    Z_qdot =  0.0;   % coupling ~ 0 (fore-aft symmetric hull)
    M_wdot =  0.0;   % = Z_qdot by symmetry

    % ── HYDRODYNAMIC DAMPING ─────────────────────────────────────────────────
    % Hull: Munk destabilising moment (horizontal and vertical planes identical)
    M_w_hull = (m11 - m22) * p.U;          % [N*m/(m/s)]  negative => destabilising

    % Aft planes: linear lifting-surface theory
    %   Plane sees heave AoA w/U and pitch-rate contribution q*x_p
    Z_w_planes = -p.rho * p.U * p.a_w * p.S_planes;               % [N/(m/s)]
    M_w_planes =  Z_w_planes * p.x_planes;                        % [N*m/(m/s)]
    Z_q_planes = -p.rho * p.U * p.a_w * p.S_planes * p.x_planes;  % [N/(rad/s)]
    M_q_planes =  Z_q_planes * p.x_planes;                        % [N*m/(rad/s)]

    % Totals
    Z_w = 0.0        + Z_w_planes;
    M_w = M_w_hull   + M_w_planes;
    Z_q = Z_q_planes;
    M_q = M_q_planes;

    % ── HYDROSTATIC RESTORING (pitch) ─────────────────────────────────────────
    % Linearised about theta = 0:
    %   Restoring moment = (z_b*Bfrc - z_g*W)*theta  [N*m/rad]
    %   Stable when z_b < z_g (CB above CG in z-down), giving M_theta < 0
    M_theta = p.z_b * Bfrc - p.z_g * W;     % [N*m/rad]
    M_hs_eq = p.x_b * Bfrc - p.x_g * W;     % trim moment at theta=0 [N*m]

    % ── M MATRIX (2x2) ───────────────────────────────────────────────────────
    %
    %  KEY SIGN: off-diagonal is -(m*x_g + Z_qdot) — NEGATIVE
    %  Source: F_z = m*(wdot + p*v - q*u) => -q*u coupling => -m*x_g
    %
    %  | m - Z_wdot,         -(m*x_g + Z_qdot) |   | wdot |
    %  | -(m*x_g + M_wdot),   I_y - M_qdot     | * | qdot |
    %
    M = [ p.m - Z_wdot,              -(p.m*p.x_g + Z_qdot) ;
         -(p.m*p.x_g + M_wdot),       p.I_y - M_qdot       ];

    % ── N MATRIX (2x3) ───────────────────────────────────────────────────────
    %
    %  KEY SIGN: Coriolis in heave row is Z_q + m*U  (ADDS m*U)
    %  Source: linearise -m*U*q (from F_z = m*(wdot - q*u)) to RHS => +m*U in N
    %
    %  Col 1 (w):     damping
    %  Col 2 (q):     damping + Coriolis (heave centripetal correction)
    %  Col 3 (theta): hydrostatic restoring — NON-ZERO  *** key difference ***
    %
    N = [ Z_w,   Z_q + p.m*p.U,           0.0     ;
          M_w,   M_q - p.m*p.x_g*p.U,     M_theta ];

    % ── CONTROL INPUT B (2x1) ────────────────────────────────────────────────
    % Positive delta => trailing-edge down => upward force at stern (z-down: -Z)
    %   => bow-up pitch moment  (+M, since x_planes < 0 and Z_delta < 0)
    Z_delta = -0.5 * p.rho * p.U^2 * p.a_w * p.S_planes;   % [N/rad]
    M_delta =  Z_delta * p.x_planes;                        % [N*m/rad]

    B = [Z_delta; M_delta];

    % ── FULL 4X4 STATE-SPACE ─────────────────────────────────────────────────
    % [zdot; wdot; qdot; thetadot] = A_sys * [w; q; theta; z] + B_sys * delta
    M_inv  = inv(M);
    A_dyn  = M_inv * N;                    % 2x3
    app_col = zeros(2,1);
    app_rows = [0, 1, 0, 0; 1, 0, 0, 0];
    A_sys  = [A_dyn , app_col; app_rows];    % 4x4 (append thetadot and z)
    B_sys  = [M_inv * B; 0; 0];             % 4x1
    
    % ── PACK RESULTS ─────────────────────────────────────────────────────────
    r.Vol      = Vol;      r.W       = W;       r.Bfrc     = Bfrc;
    r.m11      = m11;      r.m22     = m22;     r.k1       = k1;
    r.Z_wdot   = Z_wdot;   r.M_qdot  = M_qdot;
    r.Z_qdot   = Z_qdot;   r.M_wdot  = M_wdot;
    r.M_w_hull = M_w_hull;
    r.Z_w_planes = Z_w_planes;  r.M_w_planes = M_w_planes;
    r.Z_q_planes = Z_q_planes;  r.M_q_planes = M_q_planes;
    r.Z_w = Z_w;  r.M_w = M_w;  r.Z_q = Z_q;  r.M_q = M_q;
    r.M_theta = M_theta;  r.M_hs_eq = M_hs_eq;
    r.Z_delta = Z_delta;  r.M_delta = M_delta;
    r.eigs    = eig(A_sys);

end


%% SWAY-YAW MODEL
%  STATE:   x = [v, r, psi]'
%             v   — sway velocity [m/s]   (+ve = starboard)
%             r   — yaw rate     [rad/s]  (+ve = bow to starboard)
%             psi — yaw angle    [rad]    (+ve = starboard, RH about z-down)
%
%  DYNAMICS:  M * [vdot; rdot] = N * [v; r; psi] + B * delta_r
%             psidot = r                               (kinematics)
%
%  CONTROL:  delta_r [rad] — rudder deflection
%            Positive delta_r => bow to starboard
%

function [M, N, B_sy, A_sys, B_sys, r] = sway_yaw_matrices(p)
% sway_yaw_matrices  Build M (2x2), N (2x3), B (2x1) for horizontal-plane model.
%
%   Inputs:
%     p — parameter struct with fields:
%           L, D          hull length and diameter [m]
%           m, I_z        mass [kg], yaw MOI [kg*m^2]
%           x_g, y_g      CG position from hull centre [m] (y_g should be 0)
%           x_b           CB longitudinal position [m]
%           x_rudder      aft rudder x-position [m]  (< 0)
%           S_rudder      rudder planform area [m^2]
%           a_w           rudder lift-curve slope [1/rad]
%           U             forward speed [m/s]
%           rho, g        fluid density [kg/m^3], gravity [m/s^2]
%
%   Outputs:
%     M      2x2 generalised mass matrix
%     N      2x3 generalised forcing matrix  (cols: v, r, psi)
%     B      2x1 control input matrix        (rudder delta_r)
%     A_sys  3x3 full state-space A matrix   (x = [v,r,psi]')
%     B_sys  3x1 full state-space B vector
%     r      struct of all intermediate hydrodynamic quantities

    % ── VALIDATION ───────────────────────────────────────────────────────────
    assert(p.L > 0 && p.D > 0,             'L and D must be positive.');
    assert(p.m > 0 && p.I_z > 0,           'm and I_z must be positive.');
    assert(p.U > 0,                         'U must be positive.');
    assert(p.x_rudder < 0,                  'x_rudder must be negative (aft of centre).');
    assert(p.S_rudder > 0 && p.a_w > 0,    'S_rudder and a_w must be positive.');
    if abs(p.y_g) > 1e-3
        warning('AUV_MATRICES:symmetry', ...
            'y_g = %.4f m is non-zero. Model assumes port-starboard symmetry.', p.y_g);
    end

    r_hull = p.D / 2;

    % ── WEIGHT & BUOYANCY ────────────────────────────────────────────────────
    Vol  = pi * r_hull^2 * p.L;
    Bfrc = p.rho * p.g * Vol;
    W    = p.m   * p.g;

    % ── ADDED MASS (Lamb — identical formulae to pitch-heave, circular symmetry) ─
    [m11, m22, k1] = lamb_added_mass(p.L, p.D, p.rho, Vol);

    % SNAME sway-yaw derivatives (same magnitudes as Z_wdot, M_qdot)
    Y_vdot = -m22;
    N_rdot = -p.rho * pi * r_hull^2 * p.L^3 / 12.0;
    Y_rdot =  0.0;
    N_vdot =  0.0;

    % ── HYDRODYNAMIC DAMPING ─────────────────────────────────────────────────
    % Hull: horizontal-plane Munk moment (identical formula to vertical plane)
    N_v_hull = (m11 - m22) * p.U;    % [N*m/(m/s)]

    % Aft rudder: lifting-surface theory (horizontal-plane analog of stern planes)
    Y_v_rudder = -p.rho * p.U * p.a_w * p.S_rudder;
    N_v_rudder =  Y_v_rudder * p.x_rudder;
    Y_r_rudder = -p.rho * p.U * p.a_w * p.S_rudder * p.x_rudder;
    N_r_rudder =  Y_r_rudder * p.x_rudder;

    % Totals
    Y_v = 0.0        + Y_v_rudder;
    N_v = N_v_hull   + N_v_rudder;
    Y_r = Y_r_rudder;
    N_r = N_r_rudder;

    % Neutral point (lateral centre of pressure, for directional stability check)
    x_np = N_v / Y_v;   % stable iff x_np < x_g (NP aft of CG in signed coords)

    % ── HYDROSTATICS ─────────────────────────────────────────────────────────
    % N(:, psi) = 0 — no gravitational restoring moment about z-axis
    Y_psi = 0.0;
    N_psi = 0.0;

    % ── M MATRIX (2x2) ───────────────────────────────────────────────────────
    %
    %  KEY SIGN: off-diagonal is +(m*x_g - Y_rdot) — POSITIVE
    %  Source: F_y = m*(vdot + r*u) => +r*u coupling => +m*x_g
    %
    %  | m - Y_vdot,         +(m*x_g - Y_rdot) |   | vdot |
    %  | +(m*x_g - N_vdot),   I_z - N_rdot     | * | rdot |
    %
    M = [ p.m - Y_vdot,             +(p.m*p.x_g - Y_rdot) ;
         +(p.m*p.x_g - N_vdot),      p.I_z - N_rdot       ];

    % ── N MATRIX (2x3) ───────────────────────────────────────────────────────
    %
    %  KEY SIGN: Coriolis in sway row is Y_r - m*U  (SUBTRACTS m*U)
    %  Source: +m*U*r is on LHS (from F_y = m*(vdot + r*u)); moving to RHS => -m*U
    %
    %  Col 1 (v):   damping
    %  Col 2 (r):   damping + Coriolis (sway centripetal correction)
    %  Col 3 (psi): ZERO  *** no hydrostatic yaw restoring ***
    %
    N = [ Y_v,   Y_r - p.m*p.U,           Y_psi ;
          N_v,   N_r - p.m*p.x_g*p.U,     N_psi ];

    % ── CONTROL INPUT B (2x1) ────────────────────────────────────────────────
    % Positive delta_r => bow to starboard
    %   Y_delta < 0 (force to port at stern), x_rudder < 0 => N_delta > 0 (bow-stbd)
    Y_delta = -0.5 * p.rho * p.U^2 * p.a_w * p.S_rudder;
    N_delta  =  Y_delta * p.x_rudder;

    B = [Y_delta; N_delta];

    % ── FULL 3x3 STATE-SPACE ─────────────────────────────────────────────────
    % [vdot; rdot; psidot] = A_sys * [v; r; psi] + B_sys * delta_r
    M_inv  = inv(M);
    A_dyn  = M_inv * N;
    A_sys  = [A_dyn; 0, 1, 0];    % psidot = r (kinematics row)
    B_sys  = [M_inv * B; 0];
    A_sy = A_sys;
    B_sy = B_sys;

    % ── DIRECTIONAL STABILITY (Routh-Hurwitz on 2x2 [v,r] subsystem) ─────────
    A22       = A_dyn(1:2, 1:2);
    det_A22   = det(A22);
    trace_A22 = trace(A22);
    dir_stable = (det_A22 > 0) && (trace_A22 < 0);

    % ── PACK RESULTS ─────────────────────────────────────────────────────────
    r.Vol        = Vol;      r.W       = W;       r.Bfrc     = Bfrc;
    r.m11        = m11;      r.m22     = m22;     r.k1       = k1;
    r.Y_vdot     = Y_vdot;   r.N_rdot  = N_rdot;
    r.Y_rdot     = Y_rdot;   r.N_vdot  = N_vdot;
    r.N_v_hull   = N_v_hull;
    r.Y_v_rudder = Y_v_rudder;  r.N_v_rudder = N_v_rudder;
    r.Y_r_rudder = Y_r_rudder;  r.N_r_rudder = N_r_rudder;
    r.Y_v = Y_v;  r.N_v = N_v;  r.Y_r = Y_r;  r.N_r = N_r;
    r.Y_delta = Y_delta;  r.N_delta = N_delta;
    r.x_np = x_np;
    r.det_A22 = det_A22;  r.trace_A22 = trace_A22;  r.dir_stable = dir_stable;
    r.eigs    = eig(A_sys);

end


%% LAMB ADDED MASS COEFFICIENTS
function [m11, m22, k1] = lamb_added_mass(L, D, rho, Vol)
% lamb_added_mass  Axial and transverse added mass for a prolate spheroid hull.
%
%   Uses Lamb's k1 coefficient for axial (surge) added mass and the
%   2-D circular cross-section strip-theory result for transverse added mass.
%   The transverse value is identical for both heave and sway due to the
%   circular cross-section.
%
%   Inputs:
%     L, D  — hull length and diameter [m]
%     rho   — water density [kg/m^3]
%     Vol   — displaced volume [m^3]  (= pi*(D/2)^2*L for cylinder)
%
%   Outputs:
%     m11   — axial      added mass [kg]    (small for slender body)
%     m22   — transverse added mass [kg]    (= rho*pi*r^2*L)
%     k1    — Lamb's axial coefficient [-]

    fineness = L / D;
    e        = sqrt(1.0 - (1.0/fineness)^2);      % eccentricity of spheroid
    alpha0   = (2*(1 - e^2) / e^3) * (0.5*log((1+e)/(1-e)) - e);
    k1       = alpha0 / (2 - alpha0);
    m11      = k1 * rho * Vol;                     % axial added mass [kg]
    m22      = rho * pi * (D/2)^2 * L;            % transverse added mass [kg]
end