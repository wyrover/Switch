cmake_minimum_required(VERSION 3.2)

project(GroupBox)
find_package(Switch REQUIRED)
add_executable(GroupBox ${SWITCH_GUI} GroupBox.cpp README.md)
target_link_libraries(GroupBox Switch.System.Windows.Forms)
