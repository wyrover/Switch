cmake_minimum_required(VERSION 3.2)

project(EnvironmentStackTrace)
find_package(Pcf REQUIRED)
add_executable(EnvironmentStackTrace EnvironmentStackTrace.cpp)
target_link_libraries(EnvironmentStackTrace Pcf.Core)
