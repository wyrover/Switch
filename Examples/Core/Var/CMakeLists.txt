cmake_minimum_required(VERSION 3.5)

project(Var)
find_package(Pcf REQUIRED)
add_executable(Var Var.cpp)
target_link_libraries(Var Pcf.Core)
