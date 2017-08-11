cmake_minimum_required(VERSION 3.2)

project(ConsoleCursorSize)
find_package(Pcf REQUIRED)
add_executable(ConsoleCursorSize ConsoleCursorSize.cpp)
target_link_libraries(ConsoleCursorSize Pcf.Core)
