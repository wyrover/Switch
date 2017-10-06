cmake_minimum_required(VERSION 3.2)

project(HelloWorldTest)

find_package(Switch REQUIRED)
add_executable(HelloWorldTest HelloWorldTest.cpp README.md)
target_link_libraries(HelloWorldTest Switch.TUnit.Main)
