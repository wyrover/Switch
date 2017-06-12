cmake_minimum_required(VERSION 3.5)

project(SortedSet)
find_package(Pcf REQUIRED)
add_executable(SortedSet SortedSet.cpp)
target_link_libraries(SortedSet Pcf.Core)
