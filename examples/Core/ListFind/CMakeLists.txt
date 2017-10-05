cmake_minimum_required(VERSION 3.2)

project(ListFind)
find_package(Switch REQUIRED)
add_executable(ListFind ListFind.cpp)
target_link_libraries(ListFind Switch.Core)
