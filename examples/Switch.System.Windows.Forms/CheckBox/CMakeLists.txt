cmake_minimum_required(VERSION 3.2)

project(CheckBox)
find_package(Switch REQUIRED)
add_executable(CheckBox ${SWITCH_GUI} CheckBox.cpp)
target_link_libraries(CheckBox Switch.System.Windows.Forms)
