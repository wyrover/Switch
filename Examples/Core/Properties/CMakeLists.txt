cmake_minimum_required(VERSION 3.5)

project(Properties)
find_package(Pcf REQUIRED)
add_executable(Properties Properties.cpp)
target_link_libraries(Properties Pcf.Core)
