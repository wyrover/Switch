cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetEnvironmentVariable)
find_package(Switch REQUIRED)
add_executable(EnvironmentGetEnvironmentVariable EnvironmentGetEnvironmentVariable.cpp)
target_link_libraries(EnvironmentGetEnvironmentVariable Switch.System)
