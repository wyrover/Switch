cmake_minimum_required(VERSION 3.2)

project(Properties)
find_package(Switch REQUIRED)
add_executable(Properties Properties.cpp)
target_link_libraries(Properties Switch.Core)
