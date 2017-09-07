cmake_minimum_required(VERSION 3.2)

project(Form)
find_package(Switch REQUIRED)
add_executable(Form ${SWITCH_GUI} Form.cpp README.md)
target_link_libraries(Form Switch.Forms)
