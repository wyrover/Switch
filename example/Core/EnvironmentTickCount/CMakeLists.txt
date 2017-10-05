cmake_minimum_required(VERSION 3.2)

project(EnvironmentTickCount)
find_package(Switch REQUIRED)
add_executable(EnvironmentTickCount EnvironmentTickCount.cpp)
target_link_libraries(EnvironmentTickCount Switch.Core)
