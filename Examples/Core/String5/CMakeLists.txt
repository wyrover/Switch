cmake_minimum_required(VERSION 3.2)

project(String5)
find_package(Switch REQUIRED)
add_executable(String5 String5.cpp)
target_link_libraries(String5 Switch.Core)
