cmake_minimum_required(VERSION 3.2)

project(ConsoleTitle)
find_package(Switch REQUIRED)
add_executable(ConsoleTitle ConsoleTitle.cpp)
target_link_libraries(ConsoleTitle Switch.Core)
