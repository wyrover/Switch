cmake_minimum_required(VERSION 3.2)

project(SystemSound)
find_package(Pcf REQUIRED)
add_executable(SystemSound ${PCF_GUI} SystemSound.cpp)
target_link_libraries(SystemSound Pcf.Forms)
