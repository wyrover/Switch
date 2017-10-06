cmake_minimum_required(VERSION 3.2)

project(ConsoleReadKey)
find_package(Switch REQUIRED)
add_executable(ConsoleReadKey ConsoleReadKey.cpp)
target_link_libraries(ConsoleReadKey Switch.System)
