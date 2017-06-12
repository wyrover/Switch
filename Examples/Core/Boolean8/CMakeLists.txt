cmake_minimum_required(VERSION 3.5)

project(Boolean8)
find_package(Pcf REQUIRED)
add_executable(Boolean8 Boolean8.cpp)
target_link_libraries(Boolean8 Pcf.Core)
