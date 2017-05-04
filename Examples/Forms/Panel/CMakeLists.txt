cmake_minimum_required(VERSION 3.5)

project(Panel)
find_package(Pcf REQUIRED)
add_executable(Panel ${PCF_GUI} Panel.cpp)
target_link_libraries(Panel Pcf.Forms)
