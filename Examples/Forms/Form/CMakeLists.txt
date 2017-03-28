cmake_minimum_required(VERSION 3.5)

project(Form)
find_package(Pcf REQUIRED)
add_executable(Form ${PCF_GUI} Form.cpp)
target_link_libraries(Form Pcf.Forms)
