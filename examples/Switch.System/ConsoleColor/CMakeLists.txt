cmake_minimum_required(VERSION 3.2)

project(ConsoleColor)
find_package(Switch REQUIRED)
add_executable(ConsoleColor ConsoleColor.cpp)
target_link_libraries(ConsoleColor Switch.System)
