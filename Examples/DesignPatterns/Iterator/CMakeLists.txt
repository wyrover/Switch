cmake_minimum_required(VERSION 3.2)

project(Iterator)
find_package(Pcf REQUIRED)
add_executable(Iterator Iterator.cpp)
target_link_libraries(Iterator Pcf.Core)
