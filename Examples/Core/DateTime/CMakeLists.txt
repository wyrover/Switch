cmake_minimum_required(VERSION 3.5)

project(DateTime)
find_package(Pcf REQUIRED)
add_executable(DateTime DateTime.cpp)
target_link_libraries(DateTime Pcf.Core)
