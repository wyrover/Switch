cmake_minimum_required(VERSION 3.2)

project(Bridge)
find_package(Pcf REQUIRED)
add_executable(Bridge Bridge.cpp)
target_link_libraries(Bridge Pcf.Core)
