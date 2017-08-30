cmake_minimum_required(VERSION 3.2)

project(Exception)
find_package(Switch REQUIRED)
add_executable(Exception Exception.cpp)
target_link_libraries(Exception Switch.Core)
