cmake_minimum_required(VERSION 3.2)

project(SortedSet)
find_package(Switch REQUIRED)
add_executable(SortedSet SortedSet.cpp)
target_link_libraries(SortedSet Switch.System)
