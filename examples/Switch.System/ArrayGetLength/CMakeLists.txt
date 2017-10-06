cmake_minimum_required(VERSION 3.2)

project(ArrayGetLength)
find_package(Switch REQUIRED)
add_executable(ArrayGetLength ArrayGetLength.cpp README.md)
target_link_libraries(ArrayGetLength Switch.System)
