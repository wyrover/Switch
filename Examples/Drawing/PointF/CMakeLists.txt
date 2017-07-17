cmake_minimum_required(VERSION 3.2)

project(PointF)
find_package(Pcf REQUIRED)
add_executable(PointF PointF.cpp)
target_link_libraries(PointF Pcf.Drawing)
