cmake_minimum_required(VERSION 3.5)

project(Rectangle)
find_package(Pcf REQUIRED)
add_executable(Rectangle Rectangle.cpp)
target_link_libraries(Rectangle Pcf.Drawing)
