cmake_minimum_required(VERSION 3.2)

project(Prototype)
find_package(Pcf REQUIRED)
add_executable(Prototype Prototype.cpp)
target_link_libraries(Prototype Pcf.Core)
