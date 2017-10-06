cmake_minimum_required(VERSION 3.2)

project(FormClick)
find_package(Switch REQUIRED)
add_executable(FormClick ${SWITCH_GUI} FormClick.cpp README.md)
target_link_libraries(FormClick Switch.System.Windows.Forms)
