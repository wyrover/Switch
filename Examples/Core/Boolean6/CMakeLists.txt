cmake_minimum_required(VERSION 3.5)

project(Boolean6)
find_package(Pcf REQUIRED)
add_executable(Boolean6 Boolean6.cpp)
target_link_libraries(Boolean6 Pcf.Core)
