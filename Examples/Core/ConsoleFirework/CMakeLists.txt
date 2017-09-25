cmake_minimum_required(VERSION 3.2)

project(ConsoleFirework)
find_package(Switch REQUIRED)
add_executable(ConsoleFirework ConsoleFirework.cpp)
target_link_libraries(ConsoleFirework Switch.Drawing)
