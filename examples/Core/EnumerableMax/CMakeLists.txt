cmake_minimum_required(VERSION 3.2)

project(EnumerableMax)
find_package(Switch REQUIRED)
add_executable(EnumerableMax EnumerableMax.cpp)
target_link_libraries(EnumerableMax Switch.Core)
