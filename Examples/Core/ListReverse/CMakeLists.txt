cmake_minimum_required(VERSION 3.5)

project(ListReverse)
find_package(Pcf REQUIRED)
add_executable(ListReverse ListReverse.cpp)
target_link_libraries(ListReverse Pcf.Core)
