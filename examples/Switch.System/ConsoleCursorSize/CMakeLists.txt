cmake_minimum_required(VERSION 3.2)

project(ConsoleCursorSize)
find_package(Switch REQUIRED)
add_executable(ConsoleCursorSize ConsoleCursorSize.cpp)
target_link_libraries(ConsoleCursorSize Switch.System)
