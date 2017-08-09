cmake_minimum_required(VERSION 3.2)

project(Registry)
find_package(Pcf REQUIRED)
add_executable(Registry Registry.cpp)
target_link_libraries(Registry Pcf.Core)
