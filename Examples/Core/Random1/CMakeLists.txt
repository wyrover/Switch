cmake_minimum_required(VERSION 3.5)

project(Random1)
find_package(Pcf REQUIRED)
add_executable(Random1 Random1.cpp)
target_link_libraries(Random1 Pcf.Core)
