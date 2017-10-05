cmake_minimum_required(VERSION 3.2)

project(StringLiterals)
find_package(Switch REQUIRED)
add_executable(StringLiterals StringLiterals.cpp)
target_link_libraries(StringLiterals Switch.Core)
