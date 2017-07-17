cmake_minimum_required(VERSION 3.2)

project(Point)
find_package(Pcf REQUIRED)
add_executable(Point Point.cpp)
target_link_libraries(Point Pcf.Drawing)
