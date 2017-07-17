cmake_minimum_required(VERSION 3.2)

project(Thread2)
find_package(Pcf REQUIRED)
add_executable(Thread2 Thread2.cpp)
target_link_libraries(Thread2 Pcf.Core)
