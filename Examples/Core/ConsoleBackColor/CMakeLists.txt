cmake_minimum_required(VERSION 3.2)

project(ConsoleBackColor)
find_package(Pcf REQUIRED)
add_executable(ConsoleBackColor ConsoleBackColor.cpp)
target_link_libraries(ConsoleBackColor Pcf.Core)
