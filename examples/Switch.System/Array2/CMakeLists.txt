cmake_minimum_required(VERSION 3.2)

project(Array2)
find_package(Switch REQUIRED)
add_executable(Array2 Array2.cpp)
target_link_libraries(Array2 Switch.System)
