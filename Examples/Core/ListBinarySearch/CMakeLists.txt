cmake_minimum_required(VERSION 3.5)

project(ListBinarySearch)
find_package(Pcf REQUIRED)
add_executable(ListBinarySearch ListBinarySearch.cpp)
target_link_libraries(ListBinarySearch Pcf.Core)
