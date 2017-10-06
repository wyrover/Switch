cmake_minimum_required(VERSION 3.2)

project(ConsoleInfo)
find_package(Switch REQUIRED)
add_executable(ConsoleInfo ConsoleInfo.cpp)
target_link_libraries(ConsoleInfo Switch.System)
