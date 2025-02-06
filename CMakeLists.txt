cmake_minimum_required(VERSION 3.8)
project(t_motor_hardware_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

###########################################################################################
# Find dependencies
###########################################################################################
find_package(ament_cmake REQUIRED)
set(THIS_PACKAGE_ROS_DEPS
  hardware_interface
  pluginlib
  realtime_tools
  rclcpp
)
foreach(DEP ${THIS_PACKAGE_ROS_DEPS})
  find_package(${DEP} REQUIRED)
endforeach()


###########################################################################################
# Build as a library
###########################################################################################
add_library(${PROJECT_NAME} SHARED
  src/t_motor_hardware_interface.cpp
  src/t_motor/t_motor.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

foreach(DEP ${THIS_PACKAGE_ROS_DEPS})
  ament_target_dependencies(${PROJECT_NAME} ${DEP})
endforeach()

pluginlib_export_plugin_description_file(hardware_interface t_motor_hardware_interface_plugin.xml)


###########################################################################################
# Install
###########################################################################################
install(TARGETS ${PROJECT_NAME}
  DESTINATION lib
)

install(DIRECTORY include/
  DESTINATION include
)

# install(DIRECTORY launch
#   DESTINATION share/${PROJECT_NAME}
# )

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

###########################################################################################
# Ament function to export the package
###########################################################################################
ament_export_include_directories(include)
ament_export_libraries(${PROJECT_NAME})
ament_export_dependencies(${THIS_PACKAGE_ROS_DEPS})
ament_package()
