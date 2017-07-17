cmake_minimum_required(VERSION 3.2)

project(GroupBox)
find_package(Pcf REQUIRED)
add_executable(GroupBox ${PCF_GUI} GroupBox.cpp)
target_link_libraries(GroupBox Pcf.Forms)
