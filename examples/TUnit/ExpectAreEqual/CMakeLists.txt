cmake_minimum_required(VERSION 3.2)

project(ExpectAreEqual)

find_package(Switch REQUIRED)
add_executable(ExpectAreEqual ExpectAreEqual.cpp README.md)
target_link_libraries(ExpectAreEqual Switch.TUnit.Main)
