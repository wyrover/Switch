cmake_minimum_required(VERSION 3.2)

project(Foreach2)
find_package(Pcf REQUIRED)
add_executable(Foreach2 Foreach2.cpp)
target_link_libraries(Foreach2 Pcf.Core)
