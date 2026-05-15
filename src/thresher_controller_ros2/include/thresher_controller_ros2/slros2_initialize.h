// Copyright 2022-2025 The MathWorks, Inc.
// Generated 14-May-2026 19:07:03
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "THRESHER_CONTROLLER_ROS2_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, _history, _depth, _durability, _reliability, _deadline \
, _lifespan, _liveliness, _lease_duration, _avoid_ros_namespace_conventions)             \
    {                                                                                    \
        qosStruct.history = _history;                                                    \
        qosStruct.depth = _depth;                                                        \
        qosStruct.durability = _durability;                                              \
        qosStruct.reliability = _reliability;                                            \
        qosStruct.deadline.sec = _deadline.sec;                                          \
        qosStruct.deadline.nsec = _deadline.nsec;                                        \
        qosStruct.lifespan.sec = _lifespan.sec;                                          \
        qosStruct.lifespan.nsec = _lifespan.nsec;                                        \
        qosStruct.liveliness = _liveliness;                                              \
        qosStruct.liveliness_lease_duration.sec = _lease_duration.sec;                   \
        qosStruct.liveliness_lease_duration.nsec = _lease_duration.nsec;                 \
        qosStruct.avoid_ros_namespace_conventions = _avoid_ros_namespace_conventions;    \
    }
#endif
// Get QOS Settings from RMW
inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
  // pull in history & depth
  auto init = rclcpp::QoSInitialization::from_rmw(qosProfile);
  // set durability, reliability, deadline, liveliness policy, liveliness lease duration and avoid ROS namespace convention
  rclcpp::QoS qos(init, qosProfile);
  return qos;
}
// THRESHER_CONTROLLER_ROS2/Publish
extern SimulinkPublisher<geometry_msgs::msg::Point32,SL_Bus_geometry_msgs_Point32> Pub_THRESHER_CONTROLLER_ROS2_304;
// THRESHER_CONTROLLER_ROS2/Subscribe
extern SimulinkSubscriber<geometry_msgs::msg::Point,SL_Bus_geometry_msgs_Point> Sub_THRESHER_CONTROLLER_ROS2_302;
// THRESHER_CONTROLLER_ROS2/Subscribe1
extern SimulinkSubscriber<geometry_msgs::msg::Point,SL_Bus_geometry_msgs_Point> Sub_THRESHER_CONTROLLER_ROS2_303;
#endif
