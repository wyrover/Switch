cmake_minimum_required(VERSION 3.2)

project(Builder)
find_package(Switch REQUIRED)
add_executable(Builder Builder.cpp)
target_link_libraries(Builder Switch.Core)
