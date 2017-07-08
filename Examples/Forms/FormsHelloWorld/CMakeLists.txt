cmake_minimum_required(VERSION 3.5)

project(FormsHelloWorld)
find_package(Pcf REQUIRED)
add_executable(FormsHelloWorld ${PCF_GUI} FormsHelloWorld.cpp)
target_link_libraries(FormsHelloWorld Pcf.Forms)
