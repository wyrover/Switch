cmake_minimum_required(VERSION 3.2)

project(List3)
find_package(Switch REQUIRED)
add_executable(List3 List3.cpp)
target_link_libraries(List3 Switch.System)
