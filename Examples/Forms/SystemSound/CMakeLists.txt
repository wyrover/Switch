cmake_minimum_required(VERSION 3.2)

project(SystemSound)
find_package(Switch REQUIRED)
add_executable(SystemSound ${SWITCH_GUI} SystemSound.cpp)
target_link_libraries(SystemSound Switch.Forms)
