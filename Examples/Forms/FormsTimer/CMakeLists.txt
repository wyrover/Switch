cmake_minimum_required(VERSION 3.5)

project(FormsTimer)
find_package(Pcf REQUIRED)
add_executable(FormsTimer ${PCF_GUI} FormsTimer.cpp)
target_link_libraries(FormsTimer Pcf.Forms)
