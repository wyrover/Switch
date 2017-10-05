cmake_minimum_required(VERSION 3.2)

project(ConsoleCursorVisible)
find_package(Switch REQUIRED)
add_executable(ConsoleCursorVisible ConsoleCursorVisible.cpp)
target_link_libraries(ConsoleCursorVisible Switch.Core)
