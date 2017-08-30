cmake_minimum_required(VERSION 3.2)

project(String2)
find_package(Switch REQUIRED)
add_executable(String2 String2.cpp)
target_link_libraries(String2 Switch.Core)
