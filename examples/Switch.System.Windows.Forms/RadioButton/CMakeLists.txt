cmake_minimum_required(VERSION 3.2)

project(RadioButton)
find_package(Switch REQUIRED)
add_executable(RadioButton ${SWITCH_GUI} RadioButton.cpp)
target_link_libraries(RadioButton Switch.System.Windows.Forms)
