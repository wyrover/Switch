cmake_minimum_required(VERSION 3.2)

project(ConsoleKeyAvailable)
find_package(Switch REQUIRED)
add_executable(ConsoleKeyAvailable ConsoleKeyAvailable.cpp)
target_link_libraries(ConsoleKeyAvailable Switch.System)
