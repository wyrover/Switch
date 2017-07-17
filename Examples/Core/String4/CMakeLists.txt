cmake_minimum_required(VERSION 3.2)

project(String4)
find_package(Pcf REQUIRED)
add_executable(String4 String4.cpp)
target_link_libraries(String4 Pcf.Core)
