cmake_minimum_required(VERSION 3.5)

project(String3)
find_package(Pcf REQUIRED)
add_executable(String3 String3.cpp)
target_link_libraries(String3 Pcf.Core)
