cmake_minimum_required(VERSION 3.2)

project(SystemColors)
find_package(Pcf REQUIRED)
add_executable(SystemColors SystemColors.cpp)
target_link_libraries(SystemColors Pcf.Drawing)
