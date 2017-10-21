cmake_minimum_required(VERSION 3.2)

project(GroupBoxAndCheckBox)
find_package(Switch REQUIRED)
add_executable(GroupBoxAndCheckBox ${SWITCH_GUI} GroupBoxAndCheckBox.cpp README.md)
target_link_libraries(GroupBoxAndCheckBox Switch.System.Windows.Forms)
