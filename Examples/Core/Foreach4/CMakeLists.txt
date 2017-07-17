cmake_minimum_required(VERSION 3.2)

project(Foreach4)
find_package(Pcf REQUIRED)
add_executable(Foreach4 Foreach4.cpp)
target_link_libraries(Foreach4 Pcf.Core)
