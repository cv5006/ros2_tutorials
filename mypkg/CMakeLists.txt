cmake_minimum_required(VERSION 3.8)
project(mypkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)



install(DIRECTORY config xacro launch
  DESTINATION share/${PROJECT_NAME})

ament_package()
