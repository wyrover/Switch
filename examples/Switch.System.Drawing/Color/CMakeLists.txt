cmake_minimum_required(VERSION 3.2)

project(Color)
find_package(Switch REQUIRED)
add_executable(Color Color.cpp)
target_link_libraries(Color Switch.System.Drawing)
