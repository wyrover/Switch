cmake_minimum_required(VERSION 3.2)

project(SystemColors)
find_package(Switch REQUIRED)
add_executable(SystemColors SystemColors.cpp)
target_link_libraries(SystemColors Switch.Drawing)
