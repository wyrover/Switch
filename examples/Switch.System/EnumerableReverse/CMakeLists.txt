cmake_minimum_required(VERSION 3.2)

project(EnumerableReverse)
find_package(Switch REQUIRED)
add_executable(EnumerableReverse EnumerableReverse.cpp)
target_link_libraries(EnumerableReverse Switch.System)
