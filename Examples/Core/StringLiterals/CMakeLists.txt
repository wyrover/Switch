cmake_minimum_required(VERSION 3.2)

project(StringLiterals)
find_package(Pcf REQUIRED)
add_executable(StringLiterals StringLiterals.cpp)
target_link_libraries(StringLiterals Pcf.Core)
