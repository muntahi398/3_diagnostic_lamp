cmake_minimum_required(VERSION 2.8.3)
project(diagnostic_light)

find_package(catkin REQUIRED COMPONENTS genmsg roscpp std_msgs geometry_msgs message_generation)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Num.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs 
  geometry_msgs
)

catkin_package(
  INCLUDE_DIRS include
# LIBRARIES strands_gazing
  CATKIN_DEPENDS std_msgs geometry_msgs
# DEPENDS system_lib
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

## Declare a cpp executable

add_executable(diag_int_pub src/int_pub1.cpp)
target_link_libraries(diag_int_pub ${catkin_LIBRARIES})
add_executable(diag_int_sub1 src/int_sub2.cpp)
target_link_libraries(diag_int_sub1 ${catkin_LIBRARIES})

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
#add_dependencies(foo my_package_generate_messages_cpp)

## Specify libraries to link a library or executable target against

