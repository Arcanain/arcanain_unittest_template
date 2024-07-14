# cmake_minimum_required(VERSION 3.8)
# project(arcanain_unittest_template)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(ament_cmake_gtest REQUIRED)

# # Include directories
# include_directories(include)

# # simple_node
# # add_executable(simple_node src/simple_node.cpp)
# # ament_target_dependencies(simple_node rclcpp)

# # Add library for SimpleNode
# add_library(simple_node_lib src/simple_node.cpp)
# target_include_directories(simple_node_lib PUBLIC include)
# ament_target_dependencies(simple_node_lib rclcpp)

# # Add library for SimpleNode
# # add_library(simple_node_lib SHARED src/simple_node.cpp)
# # ament_target_dependencies(simple_node_lib rclcpp)

# # Add gtest
# ament_add_gtest(test_simple_node test/test_simple_node.cpp)
# if(TARGET test_simple_node)
#   target_include_directories(test_simple_node PRIVATE include)
#   target_link_libraries(test_simple_node simple_node_lib)
#   ament_target_dependencies(test_simple_node rclcpp)
# endif()

# # Enable code coverage
# if(COVERAGE)
#   if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#     message("Build with coverage information")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
#   endif()
# endif()

# # Install Cpp executables
# install(TARGETS
#   simple_node_lib
#   DESTINATION lib/${PROJECT_NAME})

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # comment the line when a copyright and license is added to all source files
#   set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # comment the line when this package is in a git repo and when
#   # a copyright and license is added to all source files
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

# ament_package()

# cmake_minimum_required(VERSION 3.8)
# project(arcanain_unittest_template)

# if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#   add_compile_options(-Wall -Wextra -Wpedantic)
# endif()

# # Find dependencies
# find_package(ament_cmake REQUIRED)
# find_package(rclcpp REQUIRED)
# find_package(ament_cmake_gtest REQUIRED)

# # Include directories
# include_directories(include)

# # Add library for SimpleNode
# add_library(simple_node_lib SHARED src/simple_node.cpp)
# target_include_directories(simple_node_lib PUBLIC include)
# ament_target_dependencies(simple_node_lib rclcpp)

# # Add gtest
# ament_add_gtest(test_simple_node test/test_simple_node.cpp)
# if(TARGET test_simple_node)
#   target_include_directories(test_simple_node PRIVATE include)
#   target_link_libraries(test_simple_node simple_node_lib)
#   ament_target_dependencies(test_simple_node rclcpp)
# endif()

# # Enable code coverage
# if(COVERAGE)
#   if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#     message("Build with coverage information")
#     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
#     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
#   endif()
# endif()

# # Install library
# install(TARGETS
#   simple_node_lib
#   DESTINATION lib/${PROJECT_NAME})

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   # the following line skips the linter which checks for copyrights
#   # comment the line when a copyright and license is added to all source files
#   set(ament_cmake_copyright_FOUND TRUE)
#   # the following line skips cpplint (only works in a git repo)
#   # comment the line when this package is in a git repo and when
#   # a copyright and license is added to all source files
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

# ament_package()

cmake_minimum_required(VERSION 3.8)
project(arcanain_unittest_template)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

# Include directories
include_directories(include)

# Add library for SimpleNode
add_library(simple_node_lib SHARED src/simple_node.cpp)
target_include_directories(simple_node_lib PUBLIC include)
ament_target_dependencies(simple_node_lib rclcpp)

# Add executable
add_executable(simple_node src/simple_node_main.cpp)
target_include_directories(simple_node PRIVATE include)
target_link_libraries(simple_node simple_node_lib)
ament_target_dependencies(simple_node rclcpp)

# Add gtest
ament_add_gtest(test_simple_node test/test_simple_node.cpp)
if(TARGET test_simple_node)
  target_include_directories(test_simple_node PRIVATE include)
  target_link_libraries(test_simple_node simple_node_lib)
  ament_target_dependencies(test_simple_node rclcpp)
endif()

# Enable code coverage
if(COVERAGE)
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message("Build with coverage information")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  endif()
endif()

# Install targets
install(TARGETS
  simple_node_lib
  simple_node
  DESTINATION lib/${PROJECT_NAME})

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

ament_package()
