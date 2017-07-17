cmake_minimum_required(VERSION 3.2)

project(ListFind)
find_package(Pcf REQUIRED)
add_executable(ListFind ListFind.cpp)
target_link_libraries(ListFind Pcf.Core)
