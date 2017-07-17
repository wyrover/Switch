cmake_minimum_required(VERSION 3.2)

project(Console)
find_package(Pcf REQUIRED)
add_executable(Console Console.cpp)
target_link_libraries(Console Pcf.Core)
