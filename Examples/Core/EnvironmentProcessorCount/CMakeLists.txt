cmake_minimum_required(VERSION 3.2)

project(EnvironmentProcessorCount)
find_package(Pcf REQUIRED)
add_executable(EnvironmentProcessorCount EnvironmentProcessorCount.cpp)
target_link_libraries(EnvironmentProcessorCount Pcf.Core)
