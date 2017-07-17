cmake_minimum_required(VERSION 3.2)

project(String5)
find_package(Pcf REQUIRED)
add_executable(String5 String5.cpp)
target_link_libraries(String5 Pcf.Core)
