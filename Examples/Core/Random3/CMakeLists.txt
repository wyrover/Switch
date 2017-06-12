cmake_minimum_required(VERSION 3.5)

project(Random3)
find_package(Pcf REQUIRED)
add_executable(Random3 Random3.cpp)
target_link_libraries(Random3 Pcf.Core)
