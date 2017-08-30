cmake_minimum_required(VERSION 3.2)

project(Object)
find_package(Switch REQUIRED)
add_executable(Object Object.cpp)
target_link_libraries(Object Switch.Core)
