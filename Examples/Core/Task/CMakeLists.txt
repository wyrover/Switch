cmake_minimum_required(VERSION 3.2)

project(Task)
find_package(Pcf REQUIRED)
add_executable(Task Task.cpp)
target_link_libraries(Task Pcf.Core)
