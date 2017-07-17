cmake_minimum_required(VERSION 3.2)

project(TrackBar)
find_package(Pcf REQUIRED)
add_executable(TrackBar ${PCF_GUI} TrackBar.cpp)
target_link_libraries(TrackBar Pcf.Forms)
