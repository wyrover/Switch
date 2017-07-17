cmake_minimum_required(VERSION 3.2)

project(ArgumentException)
find_package(Pcf REQUIRED)
add_executable(ArgumentException ArgumentException.cpp)
target_link_libraries(ArgumentException Pcf.Core)
