cmake_minimum_required(VERSION 3.5)

project(Enum2)
find_package(Pcf REQUIRED)
add_executable(Enum2 Enum2.cpp)
target_link_libraries(Enum2 Pcf.Core)
