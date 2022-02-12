cmake_minimum_required(VERSION 3.0.2)
project(system_monitor)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  diagnostic_msgs
  roscpp
  std_msgs
  message_generation
)

add_message_files(
  FILES
  SystemStatus.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
 INCLUDE_DIRS include
 LIBRARIES SystemMonitorClientLib
 CATKIN_DEPENDS message_runtime
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ executable
add_executable(central_monitor_server_node src/central_monitor_server_node.cpp src/central_monitor_server.cpp)
add_executable(client1_node src/client1_node.cpp)
add_executable(client2_node src/client2_node.cpp)
add_executable(client3_node src/client3_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(central_monitor_server_node ${central_monitor_server_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(client1_node ${client1_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(client2_node ${client2_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(client3_node ${client3_node_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(central_monitor_server_node
  ${catkin_LIBRARIES}
)
target_link_libraries(client1_node
  ${catkin_LIBRARIES}
  SystemMonitorClientLib
)
target_link_libraries(client2_node
  ${catkin_LIBRARIES}
  SystemMonitorClientLib
)
target_link_libraries(client3_node
  ${catkin_LIBRARIES}
  SystemMonitorClientLib
)

