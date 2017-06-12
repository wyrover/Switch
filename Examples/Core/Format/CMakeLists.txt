cmake_minimum_required(VERSION 3.5)

project(Format)
find_package(Pcf REQUIRED)
add_executable(Format Format.cpp)
target_link_libraries(Format Pcf.Core)
