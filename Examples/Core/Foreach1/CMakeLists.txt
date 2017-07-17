cmake_minimum_required(VERSION 3.2)

project(Foreach1)
find_package(Pcf REQUIRED)
add_executable(Foreach1 Foreach1.cpp)
target_link_libraries(Foreach1 Pcf.Core)
