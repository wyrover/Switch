cmake_minimum_required(VERSION 3.2)

project(Boolean1)
find_package(Pcf REQUIRED)
add_executable(Boolean1 Boolean1.cpp)
target_link_libraries(Boolean1 Pcf.Core)
