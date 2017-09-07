cmake_minimum_required(VERSION 3.2)

project(AssertMessage)

find_package(Switch REQUIRED)
add_executable(AssertMessage AssertMessage.cpp README.md)
target_link_libraries(AssertMessage Switch.TUnit.Main)
