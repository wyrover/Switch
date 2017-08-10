cmake_minimum_required(VERSION 3.2)

project(ConsoleColor3)
find_package(Pcf REQUIRED)
add_executable(ConsoleColor3 ConsoleColor3.cpp)
target_link_libraries(ConsoleColor3 Pcf.Core)
