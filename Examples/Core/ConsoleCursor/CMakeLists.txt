cmake_minimum_required(VERSION 3.2)

project(ConsoleCursor)
find_package(Pcf REQUIRED)
add_executable(ConsoleCursor ConsoleCursor.cpp)
target_link_libraries(ConsoleCursor Pcf.Core)
