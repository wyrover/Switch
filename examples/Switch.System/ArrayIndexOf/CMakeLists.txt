cmake_minimum_required(VERSION 3.2)

project(ArrayIndexOf)
find_package(Switch REQUIRED)
add_executable(ArrayIndexOf ArrayIndexOf.cpp README.md)
target_link_libraries(ArrayIndexOf Switch.System)
