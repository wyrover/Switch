cmake_minimum_required(VERSION 3.2)

project(HashSet)
find_package(Switch REQUIRED)
add_executable(HashSet HashSet.cpp)
target_link_libraries(HashSet Switch.Core)
