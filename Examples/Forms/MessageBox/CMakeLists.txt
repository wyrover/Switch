cmake_minimum_required(VERSION 3.2)

project(MessageBox)
find_package(Pcf REQUIRED)
add_executable(MessageBox ${PCF_GUI} MessageBox.cpp)
target_link_libraries(MessageBox Pcf.Forms)
