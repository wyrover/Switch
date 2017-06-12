cmake_minimum_required(VERSION 3.5)

project(ConsoleOut)
find_package(Pcf REQUIRED)
add_executable(ConsoleOut ConsoleOut.cpp)
target_link_libraries(ConsoleOut Pcf.Core)
