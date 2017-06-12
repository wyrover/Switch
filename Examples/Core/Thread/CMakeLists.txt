cmake_minimum_required(VERSION 3.5)

project(Thread)
find_package(Pcf REQUIRED)
add_executable(Thread Thread.cpp)
target_link_libraries(Thread Pcf.Core)
