cmake_minimum_required(VERSION 3.2)

project(Dictionary)
find_package(Switch REQUIRED)
add_executable(Dictionary Dictionary.cpp)
target_link_libraries(Dictionary Switch.System)
