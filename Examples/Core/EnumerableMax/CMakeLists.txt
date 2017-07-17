cmake_minimum_required(VERSION 3.2)

project(EnumerableMax)
find_package(Pcf REQUIRED)
add_executable(EnumerableMax EnumerableMax.cpp)
target_link_libraries(EnumerableMax Pcf.Core)
