cmake_minimum_required(VERSION 3.2)

project(Auto)
find_package(Switch REQUIRED)
add_executable(Auto Auto.cpp)
target_link_libraries(Auto Switch.Core)
