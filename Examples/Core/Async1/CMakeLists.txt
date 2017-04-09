cmake_minimum_required(VERSION 3.5)

project(Async1)
find_package(Pcf REQUIRED)
add_executable(Async1 Async1.cpp)
target_link_libraries(Async1 Pcf.Core)
