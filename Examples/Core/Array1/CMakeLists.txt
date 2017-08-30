cmake_minimum_required(VERSION 3.2)

project(Array1)
find_package(Switch REQUIRED)
add_executable(Array1 Array1.cpp)
target_link_libraries(Array1 Switch.Core)
