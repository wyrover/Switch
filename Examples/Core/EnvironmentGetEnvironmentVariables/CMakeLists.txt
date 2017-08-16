cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetEnvironmentVariables)
find_package(Pcf REQUIRED)
add_executable(EnvironmentGetEnvironmentVariables EnvironmentGetEnvironmentVariables.cpp)
target_link_libraries(EnvironmentGetEnvironmentVariables Pcf.Core)
