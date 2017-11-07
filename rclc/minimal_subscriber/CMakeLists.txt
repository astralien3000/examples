cmake_minimum_required(VERSION 3.5)
project(examples_rclc_minimal_subscriber)

find_package(ament_cmake REQUIRED)
find_package(rclc REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(subscriber_not_composable not_composable.c)
ament_target_dependencies(subscriber_not_composable rclc std_msgs)

install(TARGETS
  subscriber_not_composable
  DESTINATION lib/${PROJECT_NAME})

ament_package()
