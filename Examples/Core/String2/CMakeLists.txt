cmake_minimum_required(VERSION 3.5)

project(String2)
find_package(Pcf REQUIRED)
add_executable(String2 String2.cpp)
target_link_libraries(String2 Pcf.Core)
