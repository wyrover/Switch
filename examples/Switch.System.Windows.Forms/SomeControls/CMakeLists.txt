cmake_minimum_required(VERSION 3.2)

project(SomeControls)
find_package(Switch REQUIRED)
add_executable(SomeControls ${SWITCH_GUI} SomeControls.cpp README.md)
target_link_libraries(SomeControls Switch.System.Windows.Forms)
