cmake_minimum_required(VERSION 3.2)

project(Builder)
find_package(Pcf REQUIRED)
add_executable(Builder Builder.cpp)
target_link_libraries(Builder Pcf.Core)
