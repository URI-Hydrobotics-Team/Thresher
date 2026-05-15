/*
 * THRESHER_CONTROLLER_ROS2_types.h
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

#ifndef THRESHER_CONTROLLER_ROS2_TYPES_H_
#define THRESHER_CONTROLLER_ROS2_TYPES_H_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_BUS_GEOMETRY_MSGS_POINT_
#define DEFINED_TYPEDEF_FOR_SL_BUS_GEOMETRY_MSGS_POINT_

struct SL_Bus_geometry_msgs_Point
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_BUS_GEOMETRY_MSGS_POINT32_
#define DEFINED_TYPEDEF_FOR_SL_BUS_GEOMETRY_MSGS_POINT32_

struct SL_Bus_geometry_msgs_Point32
{
  real32_T x;
  real32_T y;
  real32_T z;
};

#endif

#ifndef STRUCT_SJ4IH70VMKCVCEGUWN0MNVF
#define STRUCT_SJ4IH70VMKCVCEGUWN0MNVF

struct sJ4ih70VmKcvCeguWN0mNVF
{
  real_T sec;
  real_T nsec;
};

#endif                                 /* STRUCT_SJ4IH70VMKCVCEGUWN0MNVF */

#ifndef STRUCT_ROS_SLROS2_INTERNAL_BLOCK_PUB_T
#define STRUCT_ROS_SLROS2_INTERNAL_BLOCK_PUB_T

struct ros_slros2_internal_block_Pub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T QOSAvoidROSNamespaceConventions;
};

#endif                              /* STRUCT_ROS_SLROS2_INTERNAL_BLOCK_PUB_T */

#ifndef STRUCT_ROS_SLROS2_INTERNAL_BLOCK_SUB_T
#define STRUCT_ROS_SLROS2_INTERNAL_BLOCK_SUB_T

struct ros_slros2_internal_block_Sub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T QOSAvoidROSNamespaceConventions;
};

#endif                              /* STRUCT_ROS_SLROS2_INTERNAL_BLOCK_SUB_T */

/* Parameters for system: '<S3>/Enabled Subsystem' */
typedef struct P_EnabledSubsystem_THRESHER_C_T_ P_EnabledSubsystem_THRESHER_C_T;

/* Parameters (default storage) */
typedef struct P_THRESHER_CONTROLLER_ROS2_T_ P_THRESHER_CONTROLLER_ROS2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_THRESHER_CONTROLLER_R_T RT_MODEL_THRESHER_CONTROLLER__T;

#endif                                 /* THRESHER_CONTROLLER_ROS2_TYPES_H_ */
