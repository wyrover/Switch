cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetEnvironmentVariables2)
find_package(Switch REQUIRED)
add_executable(EnvironmentGetEnvironmentVariables2 EnvironmentGetEnvironmentVariables2.cpp)
target_link_libraries(EnvironmentGetEnvironmentVariables2 Switch.Core)
