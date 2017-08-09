cmake_minimum_required(VERSION 3.2)

project(ConsoleColor)
find_package(Pcf REQUIRED)
add_executable(ConsoleColor ConsoleColor.cpp)
target_link_libraries(ConsoleColor Pcf.Core)
