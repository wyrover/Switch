cmake_minimum_required(VERSION 3.2)

project(ConsoleBeep2)
find_package(Switch REQUIRED)
add_executable(ConsoleBeep2 ConsoleBeep2.cpp)
target_link_libraries(ConsoleBeep2 Switch.System)
