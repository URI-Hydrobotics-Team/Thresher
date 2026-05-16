/*
 * THRESHER_CONTROLLER_ROS2.h
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

#ifndef THRESHER_CONTROLLER_ROS2_H_
#define THRESHER_CONTROLLER_ROS2_H_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "THRESHER_CONTROLLER_ROS2_types.h"
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals for system '<S3>/Enabled Subsystem' */
struct B_EnabledSubsystem_THRESHER_C_T {
  SL_Bus_geometry_msgs_Point In1;      /* '<S5>/In1' */
};

/* Block signals (default storage) */
struct B_THRESHER_CONTROLLER_ROS2_T {
  SL_Bus_geometry_msgs_Point r;
  sJ4ih70VmKcvCeguWN0mNVF deadline;
  sJ4ih70VmKcvCeguWN0mNVF deadline_m;
  sJ4ih70VmKcvCeguWN0mNVF deadline_c;
  real32_T Sum4;                       /* '<Root>/Sum4' */
  real32_T Sum3;                       /* '<Root>/Sum3' */
  B_EnabledSubsystem_THRESHER_C_T EnabledSubsystem_d;/* '<S4>/Enabled Subsystem' */
  B_EnabledSubsystem_THRESHER_C_T EnabledSubsystem;/* '<S3>/Enabled Subsystem' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_THRESHER_CONTROLLER_ROS2_T {
  ros_slros2_internal_block_Pub_T obj; /* '<S2>/SinkBlock' */
  ros_slros2_internal_block_Sub_T obj_l;/* '<S4>/SourceBlock' */
  ros_slros2_internal_block_Sub_T obj_a;/* '<S3>/SourceBlock' */
  real32_T PHOBREG_DSTATE[4];          /* '<Root>/PH OB-REG' */
  real32_T SYOBREG_DSTATE[3];          /* '<Root>/SY OB-REG' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<Root>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  boolean_T objisempty;                /* '<S4>/SourceBlock' */
  boolean_T objisempty_j;              /* '<S3>/SourceBlock' */
  boolean_T objisempty_m;              /* '<S2>/SinkBlock' */
};

/* Parameters for system: '<S3>/Enabled Subsystem' */
struct P_EnabledSubsystem_THRESHER_C_T_ {
  SL_Bus_geometry_msgs_Point Out1_Y0;  /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S5>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_THRESHER_CONTROLLER_ROS2_T_ {
  real32_T L_ph[4];                    /* Variable: L_ph
                                        * Referenced by: '<Root>/PH OB-REG'
                                        */
  real32_T L_sy[3];                    /* Variable: L_sy
                                        * Referenced by: '<Root>/SY OB-REG'
                                        */
  SL_Bus_geometry_msgs_Point Constant_Value;/* Computed Parameter: Constant_Value
                                             * Referenced by: '<S3>/Constant'
                                             */
  SL_Bus_geometry_msgs_Point Constant_Value_n;/* Computed Parameter: Constant_Value_n
                                               * Referenced by: '<S4>/Constant'
                                               */
  SL_Bus_geometry_msgs_Point32 Constant_Value_b;/* Computed Parameter: Constant_Value_b
                                                 * Referenced by: '<S1>/Constant'
                                                 */
  real32_T PHOBREG_A[16];              /* Computed Parameter: PHOBREG_A
                                        * Referenced by: '<Root>/PH OB-REG'
                                        */
  real32_T PHOBREG_C[16];              /* Computed Parameter: PHOBREG_C
                                        * Referenced by: '<Root>/PH OB-REG'
                                        */
  real32_T PHOBREG_D[4];               /* Computed Parameter: PHOBREG_D
                                        * Referenced by: '<Root>/PH OB-REG'
                                        */
  real32_T PHOBREG_InitialCondition[4];
                                 /* Computed Parameter: PHOBREG_InitialCondition
                                  * Referenced by: '<Root>/PH OB-REG'
                                  */
  real32_T SYOBREG_A[9];               /* Computed Parameter: SYOBREG_A
                                        * Referenced by: '<Root>/SY OB-REG'
                                        */
  real32_T SYOBREG_C[9];               /* Computed Parameter: SYOBREG_C
                                        * Referenced by: '<Root>/SY OB-REG'
                                        */
  real32_T SYOBREG_D[3];               /* Computed Parameter: SYOBREG_D
                                        * Referenced by: '<Root>/SY OB-REG'
                                        */
  real32_T SYOBREG_InitialCondition[3];
                                 /* Computed Parameter: SYOBREG_InitialCondition
                                  * Referenced by: '<Root>/SY OB-REG'
                                  */
  real32_T Gain2_Gain[3];              /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real32_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator2_IC
                                * Referenced by: '<Root>/Discrete-Time Integrator2'
                                */
  real32_T DiscreteTimeIntegrator2_UpperSa;
                          /* Computed Parameter: DiscreteTimeIntegrator2_UpperSa
                           * Referenced by: '<Root>/Discrete-Time Integrator2'
                           */
  real32_T DiscreteTimeIntegrator2_LowerSa;
                          /* Computed Parameter: DiscreteTimeIntegrator2_LowerSa
                           * Referenced by: '<Root>/Discrete-Time Integrator2'
                           */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real32_T Saturation2_UpperSat;     /* Computed Parameter: Saturation2_UpperSat
                                      * Referenced by: '<Root>/Saturation2'
                                      */
  real32_T Saturation2_LowerSat;     /* Computed Parameter: Saturation2_LowerSat
                                      * Referenced by: '<Root>/Saturation2'
                                      */
  real32_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_IC;
                               /* Computed Parameter: DiscreteTimeIntegrator1_IC
                                * Referenced by: '<Root>/Discrete-Time Integrator1'
                                */
  real32_T DiscreteTimeIntegrator1_UpperSa;
                          /* Computed Parameter: DiscreteTimeIntegrator1_UpperSa
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T DiscreteTimeIntegrator1_LowerSa;
                          /* Computed Parameter: DiscreteTimeIntegrator1_LowerSa
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real32_T Gain1_Gain[4];              /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Saturation1_UpperSat;     /* Computed Parameter: Saturation1_UpperSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  real32_T Saturation1_LowerSat;     /* Computed Parameter: Saturation1_LowerSat
                                      * Referenced by: '<Root>/Saturation1'
                                      */
  P_EnabledSubsystem_THRESHER_C_T EnabledSubsystem_d;/* '<S4>/Enabled Subsystem' */
  P_EnabledSubsystem_THRESHER_C_T EnabledSubsystem;/* '<S3>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_THRESHER_CONTROLLER_R_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* External function called from main */
#ifdef __cplusplus

extern "C"
{

#endif

  extern void THRESHER_CONTROLLER_ROS2_SetEventsForThisBaseStep(boolean_T
    *eventFlags, RT_MODEL_THRESHER_CONTROLLER__T *const
    THRESHER_CONTROLLER_ROS2_M);

#ifdef __cplusplus

}

#endif

/* Class declaration for model THRESHER_CONTROLLER_ROS2 */
class THRESHER_CONTROLLER_ROS2
{
  /* public data and function members */
 public:
  /* Real-Time Model get method */
  RT_MODEL_THRESHER_CONTROLLER__T * getRTM();

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step0();

  /* model step function */
  void step1();

  /* model terminate function */
  void terminate();

  /* Constructor */
  THRESHER_CONTROLLER_ROS2();

  /* Destructor */
  ~THRESHER_CONTROLLER_ROS2();

  /* private data and function members */
 private:
  /* Block signals */
  B_THRESHER_CONTROLLER_ROS2_T THRESHER_CONTROLLER_ROS2_B;

  /* Block states */
  DW_THRESHER_CONTROLLER_ROS2_T THRESHER_CONTROLLER_ROS2_DW;

  /* Tunable parameters */
  static P_THRESHER_CONTROLLER_ROS2_T THRESHER_CONTROLLER_ROS2_P;

  /* private member function(s) for subsystem '<S3>/Enabled Subsystem'*/
  static void THRES_EnabledSubsystem_Init(B_EnabledSubsystem_THRESHER_C_T
    *localB, P_EnabledSubsystem_THRESHER_C_T *localP);
  static void THRESHER_C_EnabledSubsystem(boolean_T rtu_Enable, const
    SL_Bus_geometry_msgs_Point *rtu_In1, B_EnabledSubsystem_THRESHER_C_T *localB);

  /* private member function(s) for subsystem '<Root>'*/
  void THRESHER_CO_Publisher_setupImpl(const ros_slros2_internal_block_Pub_T
    *obj);
  void THRESHER_C_Subscriber_setupImpl(const ros_slros2_internal_block_Sub_T
    *obj);
  void THRESHER_Subscriber_setupImpl_g(const ros_slros2_internal_block_Sub_T
    *obj);

  /* Real-Time Model */
  RT_MODEL_THRESHER_CONTROLLER__T THRESHER_CONTROLLER_ROS2_M;
};

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'THRESHER_CONTROLLER_ROS2'
 * '<S1>'   : 'THRESHER_CONTROLLER_ROS2/Blank Message'
 * '<S2>'   : 'THRESHER_CONTROLLER_ROS2/Publish'
 * '<S3>'   : 'THRESHER_CONTROLLER_ROS2/Subscribe'
 * '<S4>'   : 'THRESHER_CONTROLLER_ROS2/Subscribe1'
 * '<S5>'   : 'THRESHER_CONTROLLER_ROS2/Subscribe/Enabled Subsystem'
 * '<S6>'   : 'THRESHER_CONTROLLER_ROS2/Subscribe1/Enabled Subsystem'
 */
#endif                                 /* THRESHER_CONTROLLER_ROS2_H_ */
