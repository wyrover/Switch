cmake_minimum_required(VERSION 3.2)

project(ConsoleTitle)
find_package(Pcf REQUIRED)
add_executable(ConsoleTitle ConsoleTitle.cpp)
target_link_libraries(ConsoleTitle Pcf.Core)
