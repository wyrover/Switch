cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetEnvironmentVariables2)
find_package(Pcf REQUIRED)
add_executable(EnvironmentGetEnvironmentVariables2 EnvironmentGetEnvironmentVariables2.cpp)
target_link_libraries(EnvironmentGetEnvironmentVariables2 Pcf.Core)
