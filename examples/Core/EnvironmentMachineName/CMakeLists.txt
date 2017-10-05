cmake_minimum_required(VERSION 3.2)

project(EnvironmentMachineName)
find_package(Switch REQUIRED)
add_executable(EnvironmentMachineName EnvironmentMachineName.cpp)
target_link_libraries(EnvironmentMachineName Switch.Core)
