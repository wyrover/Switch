cmake_minimum_required(VERSION 3.5)

project(ObjectEquals)
find_package(Pcf REQUIRED)
add_executable(ObjectEquals ObjectEquals.cpp)
target_link_libraries(ObjectEquals Pcf.Core)
