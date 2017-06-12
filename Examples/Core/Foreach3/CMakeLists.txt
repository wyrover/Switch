cmake_minimum_required(VERSION 3.5)

project(Foreach3)
find_package(Pcf REQUIRED)
add_executable(Foreach3 Foreach3.cpp)
target_link_libraries(Foreach3 Pcf.Core)
