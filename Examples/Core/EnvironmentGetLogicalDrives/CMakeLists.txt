cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetLogicalDrives)
find_package(Pcf REQUIRED)
add_executable(EnvironmentGetLogicalDrives EnvironmentGetLogicalDrives.cpp)
target_link_libraries(EnvironmentGetLogicalDrives Pcf.Core)
