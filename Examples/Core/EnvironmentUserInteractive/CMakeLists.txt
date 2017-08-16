cmake_minimum_required(VERSION 3.2)

project(EnvironmentUserInteractive)
find_package(Pcf REQUIRED)
add_executable(EnvironmentUserInteractive EnvironmentUserInteractive.cpp)
target_link_libraries(EnvironmentUserInteractive Pcf.Core)
