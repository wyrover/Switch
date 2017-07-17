cmake_minimum_required(VERSION 3.2)

project(EnumerableAll)
find_package(Pcf REQUIRED)
add_executable(EnumerableAll EnumerableAll.cpp)
target_link_libraries(EnumerableAll Pcf.Core)
