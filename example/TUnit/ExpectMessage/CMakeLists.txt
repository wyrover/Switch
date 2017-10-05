cmake_minimum_required(VERSION 3.2)

project(ExpectMessage)

find_package(Switch REQUIRED)
add_executable(ExpectMessage ExpectMessage.cpp README.md)
target_link_libraries(ExpectMessage Switch.TUnit.Main)
