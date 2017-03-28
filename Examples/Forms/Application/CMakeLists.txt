cmake_minimum_required(VERSION 3.5)

project(Application)
find_package(Pcf REQUIRED)
add_executable(Application ${PCF_GUI} Application.cpp)
target_link_libraries(Application Pcf.Forms)
