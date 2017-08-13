cmake_minimum_required(VERSION 3.2)

project(ConsoleClear)
find_package(Pcf REQUIRED)
add_executable(ConsoleClear ConsoleClear.cpp)
target_link_libraries(ConsoleClear Pcf.Core)
