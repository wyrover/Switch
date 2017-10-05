cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetLogicalDrives)
find_package(Switch REQUIRED)
add_executable(EnvironmentGetLogicalDrives EnvironmentGetLogicalDrives.cpp)
target_link_libraries(EnvironmentGetLogicalDrives Switch.Core)
