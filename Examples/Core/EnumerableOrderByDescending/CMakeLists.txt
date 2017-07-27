cmake_minimum_required(VERSION 3.2)

project(EnumerableOrderByDescending)
find_package(Pcf REQUIRED)
add_executable(EnumerableOrderByDescending EnumerableOrderByDescending.cpp)
target_link_libraries(EnumerableOrderByDescending Pcf.Core)
