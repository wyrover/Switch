cmake_minimum_required(VERSION 3.2)

project(ConsoleOut)
find_package(Switch REQUIRED)
add_executable(ConsoleOut ConsoleOut.cpp)
target_link_libraries(ConsoleOut Switch.Core)
