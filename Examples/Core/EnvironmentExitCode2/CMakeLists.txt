cmake_minimum_required(VERSION 3.2)

project(EnvironmentExitCode2)
find_package(Pcf REQUIRED)
add_executable(EnvironmentExitCode2 EnvironmentExitCode2.cpp)
target_link_libraries(EnvironmentExitCode2 Pcf.Core)
