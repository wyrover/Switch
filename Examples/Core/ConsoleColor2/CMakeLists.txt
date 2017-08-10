cmake_minimum_required(VERSION 3.2)

project(ConsoleColor2)
find_package(Pcf REQUIRED)
add_executable(ConsoleColor2 ConsoleColor2.cpp)
target_link_libraries(ConsoleColor2 Pcf.Core)
