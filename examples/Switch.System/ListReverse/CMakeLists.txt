cmake_minimum_required(VERSION 3.2)

project(ListReverse)
find_package(Switch REQUIRED)
add_executable(ListReverse ListReverse.cpp)
target_link_libraries(ListReverse Switch.System)
