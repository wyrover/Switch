cmake_minimum_required(VERSION 3.2)

project(Math)
find_package(Switch REQUIRED)
add_executable(Math Math.cpp)
target_link_libraries(Math Switch.Core)
