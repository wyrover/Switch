cmake_minimum_required(VERSION 3.2)

project(HelloWorldForm)
find_package(Pcf REQUIRED)
add_executable(HelloWorldForm ${PCF_GUI} HelloWorldForm.cpp)
target_link_libraries(HelloWorldForm Pcf.Forms)
