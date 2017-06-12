cmake_minimum_required(VERSION 3.5)

project(Thread3)
find_package(Pcf REQUIRED)
add_executable(Thread3 Thread3.cpp)
target_link_libraries(Thread3 Pcf.Core)
