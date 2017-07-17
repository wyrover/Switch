cmake_minimum_required(VERSION 3.2)

project(RectangleF)
find_package(Pcf REQUIRED)
add_executable(RectangleF RectangleF.cpp)
target_link_libraries(RectangleF Pcf.Drawing)
