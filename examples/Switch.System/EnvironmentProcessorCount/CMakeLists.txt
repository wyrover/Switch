cmake_minimum_required(VERSION 3.2)

project(EnvironmentProcessorCount)
find_package(Switch REQUIRED)
add_executable(EnvironmentProcessorCount EnvironmentProcessorCount.cpp)
target_link_libraries(EnvironmentProcessorCount Switch.System)
