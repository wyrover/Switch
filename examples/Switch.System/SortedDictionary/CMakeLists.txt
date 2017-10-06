cmake_minimum_required(VERSION 3.2)

project(SortedDictionary)
find_package(Switch REQUIRED)
add_executable(SortedDictionary SortedDictionary.cpp)
target_link_libraries(SortedDictionary Switch.System)
