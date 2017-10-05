cmake_minimum_required(VERSION 3.2)

project(ObjectEquals)
find_package(Switch REQUIRED)
add_executable(ObjectEquals ObjectEquals.cpp)
target_link_libraries(ObjectEquals Switch.Core)
