cmake_minimum_required(VERSION 3.2)

project(List2)
find_package(Switch REQUIRED)
add_executable(List2 List2.cpp)
target_link_libraries(List2 Switch.System)
