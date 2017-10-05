cmake_minimum_required(VERSION 3.2)

project(Size)
find_package(Switch REQUIRED)
add_executable(Size Size.cpp)
target_link_libraries(Size Switch.Drawing)
