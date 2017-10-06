cmake_minimum_required(VERSION 3.2)

project(Async2)
find_package(Switch REQUIRED)
add_executable(Async2 Async2.cpp)
target_link_libraries(Async2 Switch.System)
