cmake_minimum_required(VERSION 3.5)

project(Boolean4)
find_package(Pcf REQUIRED)
add_executable(Boolean4 Boolean4.cpp)
target_link_libraries(Boolean4 Pcf.Core)
