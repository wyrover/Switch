cmake_minimum_required(VERSION 3.2)

project(Composite)
find_package(Pcf REQUIRED)
add_executable(Composite Composite.cpp)
target_link_libraries(Composite Pcf.Core)
