cmake_minimum_required(VERSION 3.2)

project(Var)
find_package(Switch REQUIRED)
add_executable(Var Var.cpp)
target_link_libraries(Var Switch.Core)
