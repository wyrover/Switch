cmake_minimum_required(VERSION 3.2)

project(MessageBox)
find_package(Switch REQUIRED)
add_executable(MessageBox ${SWITCH_GUI} MessageBox.cpp README.md)
target_link_libraries(MessageBox Switch.System.Windows.Forms)
