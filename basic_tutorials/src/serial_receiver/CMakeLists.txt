cmake_minimum_required(VERSION 3.5)
project(serial_receiver)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

INCLUDE_DIRECTORIES (include)



add_executable(serial_receiver src/serial_receiver.cc src/simple_serial.cc)
ament_target_dependencies(serial_receiver rclcpp std_msgs)

install(TARGETS
  serial_receiver
  DESTINATION lib/${PROJECT_NAME})


ament_package()
