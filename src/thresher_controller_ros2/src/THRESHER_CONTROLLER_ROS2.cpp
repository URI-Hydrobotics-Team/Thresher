/*
 * THRESHER_CONTROLLER_ROS2.cpp
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
#include "slros2_initialize.h"
#include "rtwtypes.h"
#include "THRESHER_CONTROLLER_ROS2_types.h"
#include <xmmintrin.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

static void rate_monotonic_scheduler(RT_MODEL_THRESHER_CONTROLLER__T *const
  THRESHER_CONTROLLER_ROS2_M);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void THRESHER_CONTROLLER_ROS2_SetEventsForThisBaseStep(boolean_T *eventFlags,
  RT_MODEL_THRESHER_CONTROLLER__T *const THRESHER_CONTROLLER_ROS2_M)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(THRESHER_CONTROLLER_ROS2_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(RT_MODEL_THRESHER_CONTROLLER__T *const
  THRESHER_CONTROLLER_ROS2_M)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (THRESHER_CONTROLLER_ROS2_M->Timing.TaskCounters.TID[1])++;
  if ((THRESHER_CONTROLLER_ROS2_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.1s, 0.0s] */
    THRESHER_CONTROLLER_ROS2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for enable system:
 *    '<S3>/Enabled Subsystem'
 *    '<S4>/Enabled Subsystem'
 */
void THRESHER_CONTROLLER_ROS2::THRES_EnabledSubsystem_Init
  (B_EnabledSubsystem_THRESHER_C_T *localB, P_EnabledSubsystem_THRESHER_C_T
   *localP)
{
  /* SystemInitialize for SignalConversion generated from: '<S5>/In1' incorporates:
   *  Outport: '<S5>/Out1'
   */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Output and update for enable system:
 *    '<S3>/Enabled Subsystem'
 *    '<S4>/Enabled Subsystem'
 */
void THRESHER_CONTROLLER_ROS2::THRESHER_C_EnabledSubsystem(boolean_T rtu_Enable,
  const SL_Bus_geometry_msgs_Point *rtu_In1, B_EnabledSubsystem_THRESHER_C_T
  *localB)
{
  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (rtu_Enable) {
    /* SignalConversion generated from: '<S5>/In1' */
    localB->In1 = *rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */
}

void THRESHER_CONTROLLER_ROS2::THRESHER_CO_Publisher_setupImpl(const
  ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[5];
  static const char_T b_zeroDelimTopic_0[5] = "/CMD";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S2>/SinkBlock' */
  THRESHER_CONTROLLER_ROS2_B.deadline_c.sec = 0.0;
  THRESHER_CONTROLLER_ROS2_B.deadline_c.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST,
                 static_cast<size_t>(10.0), RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE,
                 THRESHER_CONTROLLER_ROS2_B.deadline_c, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 5; i++) {
    /* Start for MATLABSystem: '<S2>/SinkBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_THRESHER_CONTROLLER_ROS2_304.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
}

void THRESHER_CONTROLLER_ROS2::THRESHER_C_Subscriber_setupImpl(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[10];
  static const char_T b_zeroDelimTopic_0[10] = "/CtrlData";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S3>/SourceBlock' */
  THRESHER_CONTROLLER_ROS2_B.deadline.sec = 0.0;
  THRESHER_CONTROLLER_ROS2_B.deadline.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST,
                 static_cast<size_t>(10.0), RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE,
                 THRESHER_CONTROLLER_ROS2_B.deadline, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 10; i++) {
    /* Start for MATLABSystem: '<S3>/SourceBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_THRESHER_CONTROLLER_ROS2_302.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
}

void THRESHER_CONTROLLER_ROS2::THRESHER_Subscriber_setupImpl_g(const
  ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  sJ4ih70VmKcvCeguWN0mNVF lifespan;
  sJ4ih70VmKcvCeguWN0mNVF liveliness_lease_duration;
  char_T b_zeroDelimTopic[9];
  static const char_T b_zeroDelimTopic_0[9] = "/CtrlCmd";
  qos_profile = rmw_qos_profile_default;

  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  THRESHER_CONTROLLER_ROS2_B.deadline_m.sec = 0.0;
  THRESHER_CONTROLLER_ROS2_B.deadline_m.nsec = 0.0;
  lifespan.sec = 0.0;
  lifespan.nsec = 0.0;
  liveliness_lease_duration.sec = 0.0;
  liveliness_lease_duration.nsec = 0.0;
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST,
                 static_cast<size_t>(10.0), RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE,
                 THRESHER_CONTROLLER_ROS2_B.deadline_m, lifespan,
                 RMW_QOS_POLICY_LIVELINESS_AUTOMATIC, liveliness_lease_duration,
                 (bool)obj->QOSAvoidROSNamespaceConventions);
  for (int32_T i = 0; i < 9; i++) {
    /* Start for MATLABSystem: '<S4>/SourceBlock' */
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_THRESHER_CONTROLLER_ROS2_303.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
}

/* Model step function for TID0 */
void THRESHER_CONTROLLER_ROS2::step0() /* Sample time: [0.05s, 0.0s] */
{
  {                                    /* Sample time: [0.05s, 0.0s] */
    rate_monotonic_scheduler((&THRESHER_CONTROLLER_ROS2_M));
  }
}

/* Model step function for TID1 */
void THRESHER_CONTROLLER_ROS2::step1() /* Sample time: [0.1s, 0.0s] */
{
  SL_Bus_geometry_msgs_Point32 rtb_BusAssignment;
  int_T i;
  real32_T rtb_PHOBREG[4];
  real32_T xnewState[3];
  real32_T PHOBREG_DSTATE;
  real32_T PHOBREG_DSTATE_0;
  real32_T PHOBREG_DSTATE_1;
  real32_T PHOBREG_DSTATE_2;
  boolean_T b_varargout_1;

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Constant: '<S1>/Constant'
   */
  rtb_BusAssignment = THRESHER_CONTROLLER_ROS2_P.Constant_Value_b;

  /* DiscreteStateSpace: '<Root>/PH OB-REG' */
  PHOBREG_DSTATE = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[1];
  PHOBREG_DSTATE_0 = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[0];
  PHOBREG_DSTATE_1 = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[2];
  PHOBREG_DSTATE_2 = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[3];
  for (i = 0; i <= 0; i += 4) {
    _mm_storeu_ps(&rtb_PHOBREG[i], _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps
      (_mm_loadu_ps(&THRESHER_CONTROLLER_ROS2_P.PHOBREG_C[i + 4]), _mm_set1_ps
       (PHOBREG_DSTATE)), _mm_mul_ps(_mm_loadu_ps
      (&THRESHER_CONTROLLER_ROS2_P.PHOBREG_C[i]), _mm_set1_ps(PHOBREG_DSTATE_0))),
      _mm_mul_ps(_mm_loadu_ps(&THRESHER_CONTROLLER_ROS2_P.PHOBREG_C[i + 8]),
                 _mm_set1_ps(PHOBREG_DSTATE_1))), _mm_mul_ps(_mm_loadu_ps
      (&THRESHER_CONTROLLER_ROS2_P.PHOBREG_C[i + 12]), _mm_set1_ps
      (PHOBREG_DSTATE_2))));
  }

  /* End of DiscreteStateSpace: '<Root>/PH OB-REG' */

  /* Gain: '<Root>/Gain2' */
  PHOBREG_DSTATE_2 = 0.0F;

  /* DiscreteStateSpace: '<Root>/SY OB-REG' */
  PHOBREG_DSTATE = THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[1];
  PHOBREG_DSTATE_0 = THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[0];
  PHOBREG_DSTATE_1 = THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[2];
  for (i = 0; i < 3; i++) {
    /* Gain: '<Root>/Gain2' incorporates:
     *  DiscreteStateSpace: '<Root>/SY OB-REG'
     */
    PHOBREG_DSTATE_2 += ((THRESHER_CONTROLLER_ROS2_P.SYOBREG_C[i + 3] *
                          PHOBREG_DSTATE +
                          THRESHER_CONTROLLER_ROS2_P.SYOBREG_C[i] *
                          PHOBREG_DSTATE_0) +
                         THRESHER_CONTROLLER_ROS2_P.SYOBREG_C[i + 6] *
                         PHOBREG_DSTATE_1) *
      THRESHER_CONTROLLER_ROS2_P.Gain2_Gain[i];
  }

  /* End of DiscreteStateSpace: '<Root>/SY OB-REG' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator2'
   *  Gain: '<Root>/Gain3'
   */
  PHOBREG_DSTATE = THRESHER_CONTROLLER_ROS2_P.Gain3_Gain *
    THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE +
    PHOBREG_DSTATE_2;

  /* Saturate: '<Root>/Saturation2' */
  if (PHOBREG_DSTATE > THRESHER_CONTROLLER_ROS2_P.Saturation2_UpperSat) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.z = THRESHER_CONTROLLER_ROS2_P.Saturation2_UpperSat;
  } else if (PHOBREG_DSTATE < THRESHER_CONTROLLER_ROS2_P.Saturation2_LowerSat) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.z = THRESHER_CONTROLLER_ROS2_P.Saturation2_LowerSat;
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.z = PHOBREG_DSTATE;
  }

  /* End of Saturate: '<Root>/Saturation2' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  DiscreteIntegrator: '<Root>/Discrete-Time Integrator1'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain4'
   */
  PHOBREG_DSTATE = (((THRESHER_CONTROLLER_ROS2_P.Gain1_Gain[0] * rtb_PHOBREG[0]
                      + THRESHER_CONTROLLER_ROS2_P.Gain1_Gain[1] * rtb_PHOBREG[1])
                     + THRESHER_CONTROLLER_ROS2_P.Gain1_Gain[2] * rtb_PHOBREG[2])
                    + THRESHER_CONTROLLER_ROS2_P.Gain1_Gain[3] * rtb_PHOBREG[3])
    + THRESHER_CONTROLLER_ROS2_P.Gain4_Gain *
    THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Saturate: '<Root>/Saturation1' */
  if (PHOBREG_DSTATE > THRESHER_CONTROLLER_ROS2_P.Saturation1_UpperSat) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.y = THRESHER_CONTROLLER_ROS2_P.Saturation1_UpperSat;
  } else if (PHOBREG_DSTATE < THRESHER_CONTROLLER_ROS2_P.Saturation1_LowerSat) {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.y = THRESHER_CONTROLLER_ROS2_P.Saturation1_LowerSat;
  } else {
    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.y = PHOBREG_DSTATE;
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* MATLABSystem: '<S2>/SinkBlock' */
  Pub_THRESHER_CONTROLLER_ROS2_304.publish(&rtb_BusAssignment);

  /* MATLABSystem: '<S3>/SourceBlock' */
  b_varargout_1 = Sub_THRESHER_CONTROLLER_ROS2_302.getLatestMessage
    (&THRESHER_CONTROLLER_ROS2_B.r);

  /* Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S3>/SourceBlock' */
  THRESHER_C_EnabledSubsystem(b_varargout_1, &THRESHER_CONTROLLER_ROS2_B.r,
    &THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S3>/Enabled Subsystem' */

  /* MATLABSystem: '<S4>/SourceBlock' */
  b_varargout_1 = Sub_THRESHER_CONTROLLER_ROS2_303.getLatestMessage
    (&THRESHER_CONTROLLER_ROS2_B.r);

  /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  THRESHER_C_EnabledSubsystem(b_varargout_1, &THRESHER_CONTROLLER_ROS2_B.r,
    &THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem_d);

  /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */

  /* Sum: '<Root>/Sum4' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   */
  THRESHER_CONTROLLER_ROS2_B.Sum4 = static_cast<real32_T>
    (THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem.In1.y) - static_cast<real32_T>
    (THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem_d.In1.y);

  /* Sum: '<Root>/Sum3' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  THRESHER_CONTROLLER_ROS2_B.Sum3 = static_cast<real32_T>
    (THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem.In1.z) - static_cast<real32_T>
    (THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem_d.In1.z);

  /* Update for DiscreteStateSpace: '<Root>/PH OB-REG' */
  PHOBREG_DSTATE = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[1];
  PHOBREG_DSTATE_0 = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[0];
  PHOBREG_DSTATE_1 = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[2];
  PHOBREG_DSTATE_2 = THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[3];
  for (i = 0; i <= 0; i += 4) {
    _mm_storeu_ps(&rtb_PHOBREG[i], _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps
      (_mm_mul_ps(_mm_loadu_ps(&THRESHER_CONTROLLER_ROS2_P.PHOBREG_A[i + 4]),
                  _mm_set1_ps(PHOBREG_DSTATE)), _mm_mul_ps(_mm_loadu_ps
      (&THRESHER_CONTROLLER_ROS2_P.PHOBREG_A[i]), _mm_set1_ps(PHOBREG_DSTATE_0))),
      _mm_mul_ps(_mm_loadu_ps(&THRESHER_CONTROLLER_ROS2_P.PHOBREG_A[i + 8]),
                 _mm_set1_ps(PHOBREG_DSTATE_1))), _mm_mul_ps(_mm_loadu_ps
      (&THRESHER_CONTROLLER_ROS2_P.PHOBREG_A[i + 12]), _mm_set1_ps
      (PHOBREG_DSTATE_2))), _mm_mul_ps(_mm_loadu_ps
      (&THRESHER_CONTROLLER_ROS2_P.L_ph[i]), _mm_set1_ps
      (THRESHER_CONTROLLER_ROS2_B.Sum3))));
  }

  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[0] = rtb_PHOBREG[0];
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[1] = rtb_PHOBREG[1];
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[2] = rtb_PHOBREG[2];
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[3] = rtb_PHOBREG[3];

  /* End of Update for DiscreteStateSpace: '<Root>/PH OB-REG' */

  /* Update for DiscreteStateSpace: '<Root>/SY OB-REG' */
  PHOBREG_DSTATE = THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[1];
  PHOBREG_DSTATE_0 = THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[0];
  PHOBREG_DSTATE_1 = THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[2];
  for (i = 0; i < 3; i++) {
    xnewState[i] = ((THRESHER_CONTROLLER_ROS2_P.SYOBREG_A[i + 3] *
                     PHOBREG_DSTATE + THRESHER_CONTROLLER_ROS2_P.SYOBREG_A[i] *
                     PHOBREG_DSTATE_0) + THRESHER_CONTROLLER_ROS2_P.SYOBREG_A[i
                    + 6] * PHOBREG_DSTATE_1) + THRESHER_CONTROLLER_ROS2_P.L_sy[i]
      * THRESHER_CONTROLLER_ROS2_B.Sum4;
  }

  THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[0] = xnewState[0];
  THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[1] = xnewState[1];
  THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[2] = xnewState[2];

  /* End of Update for DiscreteStateSpace: '<Root>/SY OB-REG' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE +=
    THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator2_gainval *
    THRESHER_CONTROLLER_ROS2_B.Sum4;
  if (THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE >
      THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator2_UpperSa) {
    THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE =
      THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator2_UpperSa;
  } else if (THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE <
             THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator2_LowerSa) {
    THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE =
      THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator2_LowerSa;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */

  /* Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE +=
    THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator1_gainval *
    THRESHER_CONTROLLER_ROS2_B.Sum3;
  if (THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE >
      THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator1_UpperSa) {
    THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE =
      THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator1_UpperSa;
  } else if (THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE <
             THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator1_LowerSa) {
    THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE =
      THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator1_LowerSa;
  }

  /* End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void THRESHER_CONTROLLER_ROS2_step(THRESHER_CONTROLLER_ROS2 &
  THRESHER_CONTROLLER_ROS2_Obj_In, int_T tid)
{
  switch (tid) {
   case 0 :
    THRESHER_CONTROLLER_ROS2_Obj_In.step0();
    break;

   case 1 :
    THRESHER_CONTROLLER_ROS2_Obj_In.step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void THRESHER_CONTROLLER_ROS2::initialize()
{
  /* Start for MATLABSystem: '<S2>/SinkBlock' */
  THRESHER_CONTROLLER_ROS2_DW.obj.QOSAvoidROSNamespaceConventions = false;
  THRESHER_CONTROLLER_ROS2_DW.obj.matlabCodegenIsDeleted = false;
  THRESHER_CONTROLLER_ROS2_DW.objisempty_m = true;
  THRESHER_CONTROLLER_ROS2_DW.obj.isSetupComplete = false;
  THRESHER_CONTROLLER_ROS2_DW.obj.isInitialized = 1;
  THRESHER_CO_Publisher_setupImpl(&THRESHER_CONTROLLER_ROS2_DW.obj);
  THRESHER_CONTROLLER_ROS2_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S3>/SourceBlock' */
  THRESHER_CONTROLLER_ROS2_DW.obj_a.QOSAvoidROSNamespaceConventions = false;
  THRESHER_CONTROLLER_ROS2_DW.obj_a.matlabCodegenIsDeleted = false;
  THRESHER_CONTROLLER_ROS2_DW.objisempty_j = true;
  THRESHER_CONTROLLER_ROS2_DW.obj_a.isSetupComplete = false;
  THRESHER_CONTROLLER_ROS2_DW.obj_a.isInitialized = 1;
  THRESHER_C_Subscriber_setupImpl(&THRESHER_CONTROLLER_ROS2_DW.obj_a);
  THRESHER_CONTROLLER_ROS2_DW.obj_a.isSetupComplete = true;

  /* Start for MATLABSystem: '<S4>/SourceBlock' */
  THRESHER_CONTROLLER_ROS2_DW.obj_l.QOSAvoidROSNamespaceConventions = false;
  THRESHER_CONTROLLER_ROS2_DW.obj_l.matlabCodegenIsDeleted = false;
  THRESHER_CONTROLLER_ROS2_DW.objisempty = true;
  THRESHER_CONTROLLER_ROS2_DW.obj_l.isSetupComplete = false;
  THRESHER_CONTROLLER_ROS2_DW.obj_l.isInitialized = 1;
  THRESHER_Subscriber_setupImpl_g(&THRESHER_CONTROLLER_ROS2_DW.obj_l);
  THRESHER_CONTROLLER_ROS2_DW.obj_l.isSetupComplete = true;

  /* InitializeConditions for DiscreteStateSpace: '<Root>/PH OB-REG' */
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[0] =
    THRESHER_CONTROLLER_ROS2_P.PHOBREG_InitialCondition[0];
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[1] =
    THRESHER_CONTROLLER_ROS2_P.PHOBREG_InitialCondition[1];
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[2] =
    THRESHER_CONTROLLER_ROS2_P.PHOBREG_InitialCondition[2];
  THRESHER_CONTROLLER_ROS2_DW.PHOBREG_DSTATE[3] =
    THRESHER_CONTROLLER_ROS2_P.PHOBREG_InitialCondition[3];

  /* InitializeConditions for DiscreteStateSpace: '<Root>/SY OB-REG' */
  THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[0] =
    THRESHER_CONTROLLER_ROS2_P.SYOBREG_InitialCondition[0];
  THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[1] =
    THRESHER_CONTROLLER_ROS2_P.SYOBREG_InitialCondition[1];
  THRESHER_CONTROLLER_ROS2_DW.SYOBREG_DSTATE[2] =
    THRESHER_CONTROLLER_ROS2_P.SYOBREG_InitialCondition[2];

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator2' */
  THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator2_DSTATE =
    THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator2_IC;

  /* InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator1' */
  THRESHER_CONTROLLER_ROS2_DW.DiscreteTimeIntegrator1_DSTATE =
    THRESHER_CONTROLLER_ROS2_P.DiscreteTimeIntegrator1_IC;

  /* SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem' */
  THRES_EnabledSubsystem_Init(&THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem,
    &THRESHER_CONTROLLER_ROS2_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  THRES_EnabledSubsystem_Init(&THRESHER_CONTROLLER_ROS2_B.EnabledSubsystem_d,
    &THRESHER_CONTROLLER_ROS2_P.EnabledSubsystem_d);

  /* End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem' */
}

/* Model terminate function */
void THRESHER_CONTROLLER_ROS2::terminate()
{
  /* Terminate for MATLABSystem: '<S2>/SinkBlock' */
  if (!THRESHER_CONTROLLER_ROS2_DW.obj.matlabCodegenIsDeleted) {
    THRESHER_CONTROLLER_ROS2_DW.obj.matlabCodegenIsDeleted = true;
    if ((THRESHER_CONTROLLER_ROS2_DW.obj.isInitialized == 1) &&
        THRESHER_CONTROLLER_ROS2_DW.obj.isSetupComplete) {
      Pub_THRESHER_CONTROLLER_ROS2_304.resetPublisherPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/SinkBlock' */

  /* Terminate for MATLABSystem: '<S3>/SourceBlock' */
  if (!THRESHER_CONTROLLER_ROS2_DW.obj_a.matlabCodegenIsDeleted) {
    THRESHER_CONTROLLER_ROS2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((THRESHER_CONTROLLER_ROS2_DW.obj_a.isInitialized == 1) &&
        THRESHER_CONTROLLER_ROS2_DW.obj_a.isSetupComplete) {
      Sub_THRESHER_CONTROLLER_ROS2_302.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/SourceBlock' */

  /* Terminate for MATLABSystem: '<S4>/SourceBlock' */
  if (!THRESHER_CONTROLLER_ROS2_DW.obj_l.matlabCodegenIsDeleted) {
    THRESHER_CONTROLLER_ROS2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((THRESHER_CONTROLLER_ROS2_DW.obj_l.isInitialized == 1) &&
        THRESHER_CONTROLLER_ROS2_DW.obj_l.isSetupComplete) {
      Sub_THRESHER_CONTROLLER_ROS2_303.resetSubscriberPtr();//();
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/SourceBlock' */
}

/* Constructor */
THRESHER_CONTROLLER_ROS2::THRESHER_CONTROLLER_ROS2() :
  THRESHER_CONTROLLER_ROS2_B(),
  THRESHER_CONTROLLER_ROS2_DW(),
  THRESHER_CONTROLLER_ROS2_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
THRESHER_CONTROLLER_ROS2::~THRESHER_CONTROLLER_ROS2()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_THRESHER_CONTROLLER__T * THRESHER_CONTROLLER_ROS2::getRTM()
{
  return (&THRESHER_CONTROLLER_ROS2_M);
}
