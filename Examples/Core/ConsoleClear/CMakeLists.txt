cmake_minimum_required(VERSION 3.2)

project(ConsoleClear)
find_package(Switch REQUIRED)
add_executable(ConsoleClear ConsoleClear.cpp)
target_link_libraries(ConsoleClear Switch.Core)
