#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/point32.hpp>
#include "THRESHER_CONTROLLER_ROS2_types.h"
#include "slros_msgconvert_utils.h"


[[maybe_unused]] static void convertFromBus(geometry_msgs::msg::Point& msgPtr, SL_Bus_geometry_msgs_Point const* busPtr);
[[maybe_unused]] static void convertToBus(SL_Bus_geometry_msgs_Point* busPtr, const geometry_msgs::msg::Point& msgPtr);

[[maybe_unused]] static void convertFromBus(geometry_msgs::msg::Point32& msgPtr, SL_Bus_geometry_msgs_Point32 const* busPtr);
[[maybe_unused]] static void convertToBus(SL_Bus_geometry_msgs_Point32* busPtr, const geometry_msgs::msg::Point32& msgPtr);



// Conversions between SL_Bus_geometry_msgs_Point and geometry_msgs::msg::Point

[[maybe_unused]] static void convertFromBus(geometry_msgs::msg::Point& msgPtr, SL_Bus_geometry_msgs_Point const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

[[maybe_unused]] static void convertToBus(SL_Bus_geometry_msgs_Point* busPtr, const geometry_msgs::msg::Point& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}


// Conversions between SL_Bus_geometry_msgs_Point32 and geometry_msgs::msg::Point32

[[maybe_unused]] static void convertFromBus(geometry_msgs::msg::Point32& msgPtr, SL_Bus_geometry_msgs_Point32 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Point32");

  msgPtr.x =  busPtr->x;
  msgPtr.y =  busPtr->y;
  msgPtr.z =  busPtr->z;
}

[[maybe_unused]] static void convertToBus(SL_Bus_geometry_msgs_Point32* busPtr, const geometry_msgs::msg::Point32& msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point32");

  busPtr->x =  msgPtr.x;
  busPtr->y =  msgPtr.y;
  busPtr->z =  msgPtr.z;
}



#endif
