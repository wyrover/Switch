cmake_minimum_required(VERSION 3.2)

project(Visitor)
find_package(Switch REQUIRED)
add_executable(Visitor Visitor.cpp)
target_link_libraries(Visitor Switch.System)
