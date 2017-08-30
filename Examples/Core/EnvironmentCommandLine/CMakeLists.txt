cmake_minimum_required(VERSION 3.2)

project(EnvironmentCommandLine)
find_package(Switch REQUIRED)
add_executable(EnvironmentCommandLine EnvironmentCommandLine.cpp)
target_link_libraries(EnvironmentCommandLine Switch.Core)
