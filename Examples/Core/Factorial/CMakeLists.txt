cmake_minimum_required(VERSION 3.2)

project(Factorial)
find_package(Switch REQUIRED)
add_executable(Factorial Factorial.cpp)
target_link_libraries(Factorial Switch.Core)
