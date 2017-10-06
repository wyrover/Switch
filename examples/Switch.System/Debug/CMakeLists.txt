cmake_minimum_required(VERSION 3.2)

project(Debug)
find_package(Switch REQUIRED)
add_executable(Debug Debug.cpp)
target_link_libraries(Debug Switch.System)
