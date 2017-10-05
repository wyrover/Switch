cmake_minimum_required(VERSION 3.2)

project(EnvironmentWorkingSet)
find_package(Switch REQUIRED)
add_executable(EnvironmentWorkingSet EnvironmentWorkingSet.cpp)
target_link_libraries(EnvironmentWorkingSet Switch.Core)
