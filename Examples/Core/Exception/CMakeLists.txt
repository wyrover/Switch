cmake_minimum_required(VERSION 3.5)

project(Exception)
find_package(Pcf REQUIRED)
add_executable(Exception Exception.cpp)
target_link_libraries(Exception Pcf.Core)
