cmake_minimum_required(VERSION 3.5)

project(String)
find_package(Pcf REQUIRED)
add_executable(String String.cpp)
target_link_libraries(String Pcf.Core)
