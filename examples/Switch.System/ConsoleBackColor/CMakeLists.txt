cmake_minimum_required(VERSION 3.2)

project(ConsoleBackColor)
find_package(Switch REQUIRED)
add_executable(ConsoleBackColor ConsoleBackColor.cpp)
target_link_libraries(ConsoleBackColor Switch.System)
