cmake_minimum_required(VERSION 3.2)

project(InterlockedDecrement)
find_package(Switch REQUIRED)
add_executable(InterlockedDecrement InterlockedDecrement.cpp)
target_link_libraries(InterlockedDecrement Switch.Core)
