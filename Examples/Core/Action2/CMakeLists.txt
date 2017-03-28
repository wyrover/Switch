cmake_minimum_required(VERSION 3.5)

project(Action2)
find_package(Pcf REQUIRED)
add_executable(Action2 Action2.cpp)
target_link_libraries(Action2 Pcf.Forms)
