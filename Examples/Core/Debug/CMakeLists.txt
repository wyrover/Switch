cmake_minimum_required(VERSION 3.5)

project(Debug)
find_package(Pcf REQUIRED)
add_executable(Debug Debug.cpp)
target_link_libraries(Debug Pcf.Core)
