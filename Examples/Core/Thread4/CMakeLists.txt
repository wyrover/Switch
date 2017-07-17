cmake_minimum_required(VERSION 3.2)

project(Thread4)
find_package(Pcf REQUIRED)
add_executable(Thread4 Thread4.cpp)
target_link_libraries(Thread4 Pcf.Core)
