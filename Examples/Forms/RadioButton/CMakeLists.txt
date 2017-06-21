cmake_minimum_required(VERSION 3.5)

project(RadioButton)
find_package(Pcf REQUIRED)
add_executable(RadioButton ${PCF_GUI} RadioButton.cpp)
target_link_libraries(RadioButton Pcf.Forms)
