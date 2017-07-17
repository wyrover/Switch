cmake_minimum_required(VERSION 3.2)

project(Main1)
find_package(Pcf REQUIRED)
add_executable(Main1 Main1.cpp)
target_link_libraries(Main1 Pcf.Core)
