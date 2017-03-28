cmake_minimum_required(VERSION 3.5)

project(Color)
find_package(Pcf REQUIRED)
add_executable(Color Color.cpp)
target_link_libraries(Color Pcf.Drawing)
