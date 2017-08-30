cmake_minimum_required(VERSION 3.2)

project(Button)
find_package(Switch REQUIRED)
add_executable(Button ${SWITCH_GUI} Button.cpp)
target_link_libraries(Button Switch.Forms)
