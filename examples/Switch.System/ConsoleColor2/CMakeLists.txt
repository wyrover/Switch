cmake_minimum_required(VERSION 3.2)

project(ConsoleColor2)
find_package(Switch REQUIRED)
add_executable(ConsoleColor2 ConsoleColor2.cpp)
target_link_libraries(ConsoleColor2 Switch.System)
