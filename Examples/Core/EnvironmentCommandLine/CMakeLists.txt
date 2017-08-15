cmake_minimum_required(VERSION 3.2)

project(EnvironmentCommandLine)
find_package(Pcf REQUIRED)
add_executable(EnvironmentCommandLine EnvironmentCommandLine.cpp)
target_link_libraries(EnvironmentCommandLine Pcf.Core)
