cmake_minimum_required(VERSION 3.2)

project(ArrayCopyTo)
find_package(Switch REQUIRED)
add_executable(ArrayCopyTo ArrayCopyTo.cpp README.md)
target_link_libraries(ArrayCopyTo Switch.System)
