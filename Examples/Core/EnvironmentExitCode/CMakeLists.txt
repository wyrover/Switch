cmake_minimum_required(VERSION 3.2)

project(EnvironmentExitCode)
find_package(Switch REQUIRED)
add_executable(EnvironmentExitCode EnvironmentExitCode.cpp)
target_link_libraries(EnvironmentExitCode Switch.Core)
