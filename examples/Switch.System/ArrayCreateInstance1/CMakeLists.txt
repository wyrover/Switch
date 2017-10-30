cmake_minimum_required(VERSION 3.2)

project(ArrayCreateInstance1)
find_package(Switch REQUIRED)
add_executable(ArrayCreateInstance1 ArrayCreateInstance1.cpp)
target_link_libraries(ArrayCreateInstance1 Switch.System)
