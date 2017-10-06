cmake_minimum_required(VERSION 3.2)

project(ConsoleRead)
find_package(Switch REQUIRED)
add_executable(ConsoleRead ConsoleRead.cpp)
target_link_libraries(ConsoleRead Switch.System)
