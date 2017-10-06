cmake_minimum_required(VERSION 3.2)

project(Boolean8)
find_package(Switch REQUIRED)
add_executable(Boolean8 Boolean8.cpp)
target_link_libraries(Boolean8 Switch.System)
