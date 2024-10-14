cmake_minimum_required(VERSION 3.8)
project(mypkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# List Packages
set(HW_IF_INCLUDE_DEPENDS
  pluginlib
  rcpputils
  hardware_interface
)

set(CONTROLLER_INCLUDE_DEPENDS
  pluginlib
  rcpputils
  controller_interface
  realtime_tools
  trajectory_msgs
)


# Find Packages
find_package(ament_cmake REQUIRED)

foreach(Dependency IN ITEMS ${HW_IF_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

foreach(Dependency IN ITEMS ${CONTROLLER_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()


# Build & Export
add_library(mycontrol SHARED
  src/myhardware.cpp
  src/mycontroller.cpp
)
target_include_directories(mycontrol PUBLIC include)

ament_target_dependencies(mycontrol PUBLIC
  ${HW_IF_INCLUDE_DEPENDS}
  ${CONTROLLER_INCLUDE_DEPENDS}
)

pluginlib_export_plugin_description_file(hardware_interface mycontrol.xml)
pluginlib_export_plugin_description_file(controller_interface mycontrol.xml)


# Install
install(TARGETS mycontrol
  DESTINATION lib
)

install(DIRECTORY config xacro launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
