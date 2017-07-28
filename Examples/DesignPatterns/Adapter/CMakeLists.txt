cmake_minimum_required(VERSION 3.2)

project(Adapter)
find_package(Pcf REQUIRED)
add_executable(Adapter Adapter.cpp)
target_link_libraries(Adapter Pcf.Core)
