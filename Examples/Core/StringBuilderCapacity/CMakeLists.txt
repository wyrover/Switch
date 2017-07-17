cmake_minimum_required(VERSION 3.2)

project(StringBuilderCapacity)
find_package(Pcf REQUIRED)
add_executable(StringBuilderCapacity StringBuilderCapacity.cpp)
target_link_libraries(StringBuilderCapacity Pcf.Core)
