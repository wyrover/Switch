cmake_minimum_required(VERSION 3.2)

project(EnumerableMin)
find_package(Pcf REQUIRED)
add_executable(EnumerableMin EnumerableMin.cpp)
target_link_libraries(EnumerableMin Pcf.Core)
