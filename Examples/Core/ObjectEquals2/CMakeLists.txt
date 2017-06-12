cmake_minimum_required(VERSION 3.5)

project(ObjectEquals2)
find_package(Pcf REQUIRED)
add_executable(ObjectEquals2 ObjectEquals2.cpp)
target_link_libraries(ObjectEquals2 Pcf.Core)
