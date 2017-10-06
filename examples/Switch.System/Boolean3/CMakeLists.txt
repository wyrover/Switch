cmake_minimum_required(VERSION 3.2)

project(Boolean3)
find_package(Switch REQUIRED)
add_executable(Boolean3 Boolean3.cpp)
target_link_libraries(Boolean3 Switch.System)
