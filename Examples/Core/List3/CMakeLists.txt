cmake_minimum_required(VERSION 3.5)

project(List3)
find_package(Pcf REQUIRED)
add_executable(List3 List3.cpp)
target_link_libraries(List3 Pcf.Core)
