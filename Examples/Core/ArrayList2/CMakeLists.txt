cmake_minimum_required(VERSION 3.2)

project(ArrayList2)
find_package(Switch REQUIRED)
add_executable(ArrayList2 ArrayList2.cpp README.md)
target_link_libraries(ArrayList2 Switch.Core)
