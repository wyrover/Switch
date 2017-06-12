cmake_minimum_required(VERSION 3.5)

project(ArrayList2)
find_package(Pcf REQUIRED)
add_executable(ArrayList2 ArrayList2.cpp)
target_link_libraries(ArrayList2 Pcf.Core)
