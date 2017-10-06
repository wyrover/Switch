cmake_minimum_required(VERSION 3.2)

project(Boolean6)
find_package(Switch REQUIRED)
add_executable(Boolean6 Boolean6.cpp)
target_link_libraries(Boolean6 Switch.System)
