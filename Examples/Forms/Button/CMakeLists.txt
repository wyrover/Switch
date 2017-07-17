cmake_minimum_required(VERSION 3.2)

project(Button)
find_package(Pcf REQUIRED)
add_executable(Button ${PCF_GUI} Button.cpp)
target_link_libraries(Button Pcf.Forms)
