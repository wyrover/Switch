cmake_minimum_required(VERSION 3.2)

project(EnvironmentOSVersion)
find_package(Switch REQUIRED)
add_executable(EnvironmentOSVersion EnvironmentOSVersion.cpp)
target_link_libraries(EnvironmentOSVersion Switch.Core)
