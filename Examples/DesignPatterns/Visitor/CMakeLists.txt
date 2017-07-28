cmake_minimum_required(VERSION 3.2)

project(Visitor)
find_package(Pcf REQUIRED)
add_executable(Visitor Visitor.cpp)
target_link_libraries(Visitor Pcf.Core)
