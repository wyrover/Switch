cmake_minimum_required(VERSION 3.5)

project(CheckBox)
find_package(Pcf REQUIRED)
add_executable(CheckBox ${PCF_GUI} CheckBox.cpp)
target_link_libraries(CheckBox Pcf.Forms)
