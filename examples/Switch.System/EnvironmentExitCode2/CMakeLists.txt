cmake_minimum_required(VERSION 3.2)

project(EnvironmentExitCode2)
find_package(Switch REQUIRED)
add_executable(EnvironmentExitCode2 EnvironmentExitCode2.cpp)
target_link_libraries(EnvironmentExitCode2 Switch.System)
