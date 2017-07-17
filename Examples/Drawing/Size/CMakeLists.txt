cmake_minimum_required(VERSION 3.2)

project(Size)
find_package(Pcf REQUIRED)
add_executable(Size Size.cpp)
target_link_libraries(Size Pcf.Drawing)
