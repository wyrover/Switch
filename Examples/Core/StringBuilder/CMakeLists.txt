cmake_minimum_required(VERSION 3.5)

project(StringBuilder)
find_package(Pcf REQUIRED)
add_executable(StringBuilder StringBuilder.cpp)
target_link_libraries(StringBuilder Pcf.Core)
