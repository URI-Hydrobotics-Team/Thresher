/*
 * THRESHER_CONTROLLER_ROS2_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "THRESHER_CONTROLLER_ROS2".
 *
 * Model version              : 13.1
 * Simulink Coder version : 26.1 (R2026a) 20-Nov-2025
 * C++ source code generated on : Thu May 14 19:06:59 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "THRESHER_CONTROLLER_ROS2.h"

/* Block parameters (default storage) */
P_THRESHER_CONTROLLER_ROS2_T THRESHER_CONTROLLER_ROS2::
  THRESHER_CONTROLLER_ROS2_P = {
  /* Variable: L_ph
   * Referenced by: '<Root>/PH OB-REG'
   */
  { 0.60043031F, -0.823720276F, 0.241023719F, -0.162379399F },

  /* Variable: L_sy
   * Referenced by: '<Root>/SY OB-REG'
   */
  { 0.00513665937F, 0.673694253F, -0.176282525F },

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S3>/Constant'
   */
  {
    0.0,                               /* x */
    0.0,                               /* y */
    0.0                                /* z */
  },

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S4>/Constant'
   */
  {
    0.0,                               /* x */
    0.0,                               /* y */
    0.0                                /* z */
  },

  /* Computed Parameter: Constant_Value_b
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0F,                              /* x */
    0.0F,                              /* y */
    0.0F                               /* z */
  },

  /* Computed Parameter: PHOBREG_A
   * Referenced by: '<Root>/PH OB-REG'
   */
  { 0.869570196F, 0.116844855F, 0.00613960251F, 0.0932223499F, 0.111682117F,
    0.72399503F, 0.0854827464F, 0.00601288211F, 0.0251502674F, -0.190567672F,
    0.989935398F, 0.0015070407F, -0.630846858F, 0.988360405F, -0.232330799F,
    1.16063523F },

  /* Computed Parameter: PHOBREG_C
   * Referenced by: '<Root>/PH OB-REG'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 1.0F },

  /* Computed Parameter: PHOBREG_D
   * Referenced by: '<Root>/PH OB-REG'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: PHOBREG_InitialCondition
   * Referenced by: '<Root>/PH OB-REG'
   */
  { 0.0F, 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: SYOBREG_A
   * Referenced by: '<Root>/SY OB-REG'
   */
  { 0.895807803F, -0.023930097F, -0.00129671523F, 0.0147482054F, 0.693168938F,
    0.0838056058F, 0.0130562112F, -0.748228967F, 1.17235327F },

  /* Computed Parameter: SYOBREG_C
   * Referenced by: '<Root>/SY OB-REG'
   */
  { 1.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 1.0F },

  /* Computed Parameter: SYOBREG_D
   * Referenced by: '<Root>/SY OB-REG'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: SYOBREG_InitialCondition
   * Referenced by: '<Root>/SY OB-REG'
   */
  { 0.0F, 0.0F, 0.0F },

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  { 0.0231603067F, -0.0707699582F, -0.247992963F },

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  0.1F,

  /* Computed Parameter: DiscreteTimeIntegrator2_IC
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  243.951187F,

  /* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  -243.951187F,

  /* Computed Parameter: Gain3_Gain
   * Referenced by: '<Root>/Gain3'
   */
  -0.00214632601F,

  /* Computed Parameter: Saturation2_UpperSat
   * Referenced by: '<Root>/Saturation2'
   */
  0.52359879F,

  /* Computed Parameter: Saturation2_LowerSat
   * Referenced by: '<Root>/Saturation2'
   */
  -0.52359879F,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.1F,

  /* Computed Parameter: DiscreteTimeIntegrator1_IC
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  289.79184F,

  /* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  -289.79184F,

  /* Computed Parameter: Gain4_Gain
   * Referenced by: '<Root>/Gain4'
   */
  0.0018068098F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  { 0.472461253F, 0.0526623242F, -0.497813523F, 0.543440044F },

  /* Computed Parameter: Saturation1_UpperSat
   * Referenced by: '<Root>/Saturation1'
   */
  0.52359879F,

  /* Computed Parameter: Saturation1_LowerSat
   * Referenced by: '<Root>/Saturation1'
   */
  -0.52359879F,

  /* Start of '<S4>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S6>/Out1'
     */
    {
      0.0,                             /* x */
      0.0,                             /* y */
      0.0                              /* z */
    }
  }
  ,

  /* End of '<S4>/Enabled Subsystem' */

  /* Start of '<S3>/Enabled Subsystem' */
  {
    /* Computed Parameter: Out1_Y0
     * Referenced by: '<S5>/Out1'
     */
    {
      0.0,                             /* x */
      0.0,                             /* y */
      0.0                              /* z */
    }
  }
  /* End of '<S3>/Enabled Subsystem' */
};
