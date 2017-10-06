cmake_minimum_required(VERSION 3.2)

project(Application)
find_package(Switch REQUIRED)
add_executable(Application ${SWITCH_GUI} Application.cpp README.md)
target_link_libraries(Application Switch.System.Windows.Forms)
