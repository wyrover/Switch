cmake_minimum_required(VERSION 3.2)

project(ArrayList)
find_package(Switch REQUIRED)
add_executable(ArrayList ArrayList.cpp)
target_link_libraries(ArrayList Switch.Core)
