cmake_minimum_required(VERSION 3.2)

project(ConsoleBuffer)
find_package(Switch REQUIRED)
add_executable(ConsoleBuffer ConsoleBuffer.cpp)
target_link_libraries(ConsoleBuffer Switch.System)
