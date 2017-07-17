cmake_minimum_required(VERSION 3.2)

project(Boolean2)
find_package(Pcf REQUIRED)
add_executable(Boolean2 Boolean2.cpp)
target_link_libraries(Boolean2 Pcf.Core)
