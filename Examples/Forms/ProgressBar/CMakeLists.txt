cmake_minimum_required(VERSION 3.2)

project(ProgressBar)
find_package(Pcf REQUIRED)
add_executable(ProgressBar ${PCF_GUI} ProgressBar.cpp)
target_link_libraries(ProgressBar Pcf.Forms)
