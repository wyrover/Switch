cmake_minimum_required(VERSION 3.2)

project(ConsoleColor4)
find_package(Pcf REQUIRED)
add_executable(ConsoleColor4 ConsoleColor4.cpp)
target_link_libraries(ConsoleColor4 Pcf.Core)
