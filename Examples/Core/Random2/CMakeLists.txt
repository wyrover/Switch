cmake_minimum_required(VERSION 3.5)

project(Random2)
find_package(Pcf REQUIRED)
add_executable(Random2 Random2.cpp)
target_link_libraries(Random2 Pcf.Core)
