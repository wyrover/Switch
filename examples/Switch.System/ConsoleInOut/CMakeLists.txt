cmake_minimum_required(VERSION 3.2)

project(ConsoleInOut)
find_package(Switch REQUIRED)
add_executable(ConsoleInOut ConsoleInOut.cpp)
target_link_libraries(ConsoleInOut Switch.System)
