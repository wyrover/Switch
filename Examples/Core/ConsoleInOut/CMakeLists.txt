cmake_minimum_required(VERSION 3.2)

project(ConsoleInOut)
find_package(Pcf REQUIRED)
add_executable(ConsoleInOut ConsoleInOut.cpp)
target_link_libraries(ConsoleInOut Pcf.Core)
