cmake_minimum_required(VERSION 3.2)

project(Async2)
find_package(Pcf REQUIRED)
add_executable(Async2 Async2.cpp)
target_link_libraries(Async2 Pcf.Core)
