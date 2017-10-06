cmake_minimum_required(VERSION 3.2)

project(HelloWorldForm)
find_package(Switch REQUIRED)
add_executable(HelloWorldForm ${SWITCH_GUI} HelloWorldForm.cpp README.md)
target_link_libraries(HelloWorldForm Switch.System.Windows.Forms)
