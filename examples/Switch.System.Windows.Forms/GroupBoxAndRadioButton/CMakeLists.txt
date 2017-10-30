cmake_minimum_required(VERSION 3.2)

project(GroupBoxAndRadioButton)
find_package(Switch REQUIRED)
add_executable(GroupBoxAndRadioButton ${SWITCH_GUI} GroupBoxAndRadioButton.cpp)
target_link_libraries(GroupBoxAndRadioButton Switch.System.Windows.Forms)
