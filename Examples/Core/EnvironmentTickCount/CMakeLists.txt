cmake_minimum_required(VERSION 3.2)

project(EnvironmentTickCount)
find_package(Pcf REQUIRED)
add_executable(EnvironmentTickCount EnvironmentTickCount.cpp)
target_link_libraries(EnvironmentTickCount Pcf.Core)
