cmake_minimum_required(VERSION 3.5)

project(List)
find_package(Pcf REQUIRED)
add_executable(List List.cpp)
target_link_libraries(List Pcf.Core)
