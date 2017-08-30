cmake_minimum_required(VERSION 3.2)

project(Rectangle)
find_package(Switch REQUIRED)
add_executable(Rectangle Rectangle.cpp)
target_link_libraries(Rectangle Switch.Drawing)
