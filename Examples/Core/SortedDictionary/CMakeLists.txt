cmake_minimum_required(VERSION 3.2)

project(SortedDictionary)
find_package(Pcf REQUIRED)
add_executable(SortedDictionary SortedDictionary.cpp)
target_link_libraries(SortedDictionary Pcf.Core)
