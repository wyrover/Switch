cmake_minimum_required(VERSION 3.2)

project(ArrayList)
find_package(Pcf REQUIRED)
add_executable(ArrayList ArrayList.cpp)
target_link_libraries(ArrayList Pcf.Core)
