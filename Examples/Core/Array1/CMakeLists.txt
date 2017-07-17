cmake_minimum_required(VERSION 3.2)

project(Array1)
find_package(Pcf REQUIRED)
add_executable(Array1 Array1.cpp)
target_link_libraries(Array1 Pcf.Core)
