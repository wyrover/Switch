cmake_minimum_required(VERSION 3.2)

project(Foreach3)
find_package(Switch REQUIRED)
add_executable(Foreach3 Foreach3.cpp)
target_link_libraries(Foreach3 Switch.Core)
