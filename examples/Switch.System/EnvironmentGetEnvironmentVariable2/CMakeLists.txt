cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetEnvironmentVariable2)
find_package(Switch REQUIRED)
add_executable(EnvironmentGetEnvironmentVariable2 EnvironmentGetEnvironmentVariable2.cpp)
target_link_libraries(EnvironmentGetEnvironmentVariable2 Switch.System)
