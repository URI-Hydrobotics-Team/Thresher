%% THRESHER CONTROLLER DESIGN %%
clc; close all; clear all
load("sroots.mat"); % R.J Vaccaro
run("THRESHER_DYNAMIC_MODEL.m");

T = .1; % Sampling Time

%% PH System
C_ph = [0, 0, 0, 1];
Ts = 40; % Settling Time
sPoles_ph = getSpoles(A_ph, Ts, height(C_ph));
zPoles_ph = exp(T*sPoles_ph);
[PHI_ph, GAMMA_ph] = c2d(A_ph, Bsys_ph, T);
 
% Additional Dynamics
PHI_a_ph = eye(height(C_ph));
GAMMA_a_ph = PHI_a_ph;

[K1_ph, K2_ph, ad1_ph, ad2_ph] = tsd(PHI_ph, GAMMA_ph, C_ph, PHI_a_ph,...
  GAMMA_a_ph, zPoles_ph, T, 'place');

% Observer params
Tso = Ts/5;
SoPoles = s4/Tso;
ZoPoles = exp(T*SoPoles);

[L_ph, od1_ph, od2_ph] = obg_reg(PHI_ph,GAMMA_ph,C_ph,K1_ph,ZoPoles,T);

dsm_regob(PHI_ph,GAMMA_ph,C_ph,K1_ph,L_ph)

Ca_ph = eye(4);
Ca_ph(4,4) = -1;


%% SY Systsem
C_sy = [0, 0, 1];
Ts = 30; % Settling Time
sPoles_sy = getSpoles(A_sy, Ts, height(C_sy));
zPoles_sy = exp(sPoles_sy*T);
[PHI_sy, GAMMA_sy] = c2d(A_sy, Bsys_sy, T);

% Additional Dynamics
PHI_a_sy = eye(height(C_sy));
GAMMA_a_sy = PHI_a_sy;
[K1_sy, K2_sy, ad1_sy, ad2_sy] = tsd(PHI_sy, GAMMA_sy, C_sy, PHI_a_sy,...
    GAMMA_a_sy, zPoles_sy, T, 'place');

% Observer params
Tso = Ts/5;
SoPoles = s3/Tso;
ZoPoles = exp(T*SoPoles);

[L_sy, od1_sy, od2_sy] = obg_reg(PHI_sy,GAMMA_sy,C_sy,K1_sy,ZoPoles,T);

dsm_regob(PHI_sy,GAMMA_sy,C_sy,K1_sy,L_sy)




function sPoles = getSpoles(A, Ts, MORE)
    % Calculates sPole Locations
    load("sroots.mat"); % R.J Vaccaro

    UnReg = eig(A);

    n = width(A);

    Cutoff = s1/Ts;

    SDP_ind = real(UnReg) < Cutoff;

    ADP_ind = ((abs(imag(UnReg)) > 0) - SDP_ind) > 0;

    UDP_ind = ones(n, 1) - ADP_ind - SDP_ind;

    sPoles = UnReg(SDP_ind)';

    ADP = (1i*imag(UnReg)+Cutoff);

    sPoles = [sPoles, ADP(ADP_ind)'];

    sPoles = [sPoles , eval(append('s',num2str((sum(UDP_ind)+MORE))))/Ts];
end
