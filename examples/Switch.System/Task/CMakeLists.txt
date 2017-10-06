cmake_minimum_required(VERSION 3.2)

project(Task)
find_package(Switch REQUIRED)
add_executable(Task Task.cpp)
target_link_libraries(Task Switch.System)
