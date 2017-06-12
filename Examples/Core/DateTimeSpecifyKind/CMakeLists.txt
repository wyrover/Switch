cmake_minimum_required(VERSION 3.5)

project(DateTimeSpecifyKind)
find_package(Pcf REQUIRED)
add_executable(DateTimeSpecifyKind DateTimeSpecifyKind.cpp)
target_link_libraries(DateTimeSpecifyKind Pcf.Core)
