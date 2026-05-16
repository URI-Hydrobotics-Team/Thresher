cmake_minimum_required(VERSION 3.5)
project(thresher_controller_ros2)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Set CMAKE_BUILD_TYPE
set(CMAKE_BUILD_TYPE Release)
set(MW_TOP_LEVEL_PROJECT_NAME ${PROJECT_NAME})
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
if(ALIAS_ROS2_TF2)
  add_definitions(-Dtf2=ros2_tf2)
  add_definitions(-Dtf2_ros=ros2_tf2_ros)
  add_definitions(-Dmessage_filters=ros2_message_filters)
endif()
# Check the ROS 2 distribution and define a macro
if("$ENV{ROS_DISTRO}" STREQUAL "humble")
    message(STATUS "Building for ROS 2 Humble")
    add_definitions(-DROS2_DISTRO_HUMBLE)
elseif("$ENV{ROS_DISTRO}" STREQUAL "jazzy")
    message(STATUS "Building for ROS 2 Jazzy")
    add_definitions(-DROS2_DISTRO_JAZZY)
else()
    message(WARNING "ROS 2 distribution $ENV{ROS_DISTRO} is not recommended for this MATLAB version. Use 'ROS 2 Jazzy' for this MATLAB version.")
    message(WARNING "Building for ROS 2 Jazzy")
    add_definitions(-DROS2_DISTRO_JAZZY)
endif()
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package( geometry_msgs REQUIRED)
find_package( rclcpp REQUIRED)
# Add package include directories
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/thresher_controller_ros2")
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# Node
add_executable(THRESHER_CONTROLLER_ROS2 
src/THRESHER_CONTROLLER_ROS2.cpp
src/THRESHER_CONTROLLER_ROS2_data.cpp
src/main.cpp
src/ros2nodeinterface.cpp
src/slros2_initialize.cpp
src/slros2_multi_threaded_executor.cpp
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
target_compile_options(THRESHER_CONTROLLER_ROS2 PUBLIC 
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -Wall -Wextra -Wpedantic
  >)
endif()
target_compile_options(THRESHER_CONTROLLER_ROS2 PRIVATE
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -DMODEL=THRESHER_CONTROLLER_ROS2
  -DNUMST=2
  -DNCSTATES=0
  -DHAVESTDIO
  -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
  -DCLASSIC_INTERFACE=0
  -DALLOCATIONFCN=0
  -DTID01EQ=0
  -DONESTEPFCN=1
  -DTERMFCN=1
  -DMULTI_INSTANCE_CODE=1
  -DINTEGER_CODE=0
  -DMT=1
  -DROS2_PROJECT
  -DSTACK_SIZE=64
  -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
  -DMW_SOCKETCAN_NUM_INTERFACES=1
  -DMW_SOCKETCAN_IF_NAME0=can0
  -DMW_SOCKETCAN_IF_REAL0=1
  -DMW_SOCKETCAN_IF_SPEED0=500000
  -DMW_SOCKETCAN_IF_QUEUE0=65536
  -DMW_SOCKETCAN_IF_NAME1=can1
  -DMW_SOCKETCAN_IF_REAL1=1
  -DMW_SOCKETCAN_IF_SPEED1=500000
  -DMW_SOCKETCAN_IF_QUEUE1=65536
  -DMW_SOCKETCAN_IF_NAME2=can2
  -DMW_SOCKETCAN_IF_REAL2=1
  -DMW_SOCKETCAN_IF_SPEED2=500000
  -DMW_SOCKETCAN_IF_QUEUE2=65536
  -DMW_SOCKETCAN_IF_NAME3=can3
  -DMW_SOCKETCAN_IF_REAL3=1
  -DMW_SOCKETCAN_IF_SPEED3=500000
  -DMW_SOCKETCAN_IF_QUEUE3=65536
  -DMW_SOCKETCAN_IF_NAME4=can4
  -DMW_SOCKETCAN_IF_REAL4=1
  -DMW_SOCKETCAN_IF_SPEED4=500000
  -DMW_SOCKETCAN_IF_QUEUE4=65536
  -DMW_CAN_ALLOWALLMSGS=1
  -DRT=RT
  -fpermissive  >
  )
ament_target_dependencies(
  THRESHER_CONTROLLER_ROS2
  "geometry_msgs"
  "rclcpp"
)
target_include_directories(THRESHER_CONTROLLER_ROS2 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(THRESHER_CONTROLLER_ROS2 
	${CMAKE_DL_LIBS}
    )
install(TARGETS THRESHER_CONTROLLER_ROS2
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
ament_export_include_directories(
  include
)
foreach(file_i ${CUDA_BINS})
add_custom_command(
                   TARGET THRESHER_CONTROLLER_ROS2
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CMAKE_INSTALL_PREFIX}/THRESHER_CONTROLLER_ROS2_ert_rtw/${file_i}
				   )
add_custom_command(
                   TARGET THRESHER_CONTROLLER_ROS2
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CMAKE_INSTALL_PREFIX}/codegen/exe/THRESHER_CONTROLLER_ROS2/${file_i}
				   )				   
endforeach(file_i)
ament_package()
# Generated on Thu May 14 19:07:05 2026
