cmake_minimum_required(VERSION 3.2)

project(Exception1)
find_package(Switch REQUIRED)
add_executable(Exception1 Exception1.cpp)
target_link_libraries(Exception1 Switch.Core)
