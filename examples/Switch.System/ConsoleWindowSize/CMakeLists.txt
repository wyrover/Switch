cmake_minimum_required(VERSION 3.2)

project(ConsoleWindowSize)
find_package(Switch REQUIRED)
add_executable(ConsoleWindowSize ConsoleWindowSize.cpp)
target_link_libraries(ConsoleWindowSize Switch.System)
