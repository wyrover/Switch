cmake_minimum_required(VERSION 3.2)

project(Environment)
find_package(Pcf REQUIRED)
add_executable(Environment Environment.cpp)
target_link_libraries(Environment Pcf.Core)
