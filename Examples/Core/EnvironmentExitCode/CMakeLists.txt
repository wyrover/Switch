cmake_minimum_required(VERSION 3.2)

project(EnvironmentExitCode)
find_package(Pcf REQUIRED)
add_executable(EnvironmentExitCode EnvironmentExitCode.cpp)
target_link_libraries(EnvironmentExitCode Pcf.Core)
