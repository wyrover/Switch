cmake_minimum_required(VERSION 3.2)

project(ProgressBar)
find_package(Switch REQUIRED)
add_executable(ProgressBar ${SWITCH_GUI} ProgressBar.cpp README.md)
target_link_libraries(ProgressBar Switch.Forms)
