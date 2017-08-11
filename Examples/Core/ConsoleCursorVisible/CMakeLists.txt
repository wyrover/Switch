cmake_minimum_required(VERSION 3.2)

project(ConsoleCursorVisible)
find_package(Pcf REQUIRED)
add_executable(ConsoleCursorVisible ConsoleCursorVisible.cpp)
target_link_libraries(ConsoleCursorVisible Pcf.Core)
