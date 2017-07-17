cmake_minimum_required(VERSION 3.2)

project(Math)
find_package(Pcf REQUIRED)
add_executable(Math Math.cpp)
target_link_libraries(Math Pcf.Core)
