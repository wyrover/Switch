cmake_minimum_required(VERSION 3.2)

project(TimerForm)
find_package(Pcf REQUIRED)
add_executable(TimerForm ${PCF_GUI} TimerForm.cpp)
target_link_libraries(TimerForm Pcf.Forms)
