cmake_minimum_required(VERSION 3.2)

project(LinqAgregate)
find_package(Switch REQUIRED)
add_executable(LinqAgregate LinqAgregate.cpp)
target_link_libraries(LinqAgregate Switch.Core)
