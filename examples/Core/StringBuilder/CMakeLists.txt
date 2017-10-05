cmake_minimum_required(VERSION 3.2)

project(StringBuilder)
find_package(Switch REQUIRED)
add_executable(StringBuilder StringBuilder.cpp)
target_link_libraries(StringBuilder Switch.Core)
