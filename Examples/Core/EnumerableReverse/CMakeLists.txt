cmake_minimum_required(VERSION 3.2)

project(EnumerableReverse)
find_package(Pcf REQUIRED)
add_executable(EnumerableReverse EnumerableReverse.cpp)
target_link_libraries(EnumerableReverse Pcf.Core)
