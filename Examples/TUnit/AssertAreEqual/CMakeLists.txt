cmake_minimum_required(VERSION 3.2)

project(AssertAreEqual)

find_package(Switch REQUIRED)
add_executable(AssertAreEqual AssertAreEqual.cpp README.md)
target_link_libraries(AssertAreEqual Switch.TUnit.Main)
