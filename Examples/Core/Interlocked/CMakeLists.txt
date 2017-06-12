cmake_minimum_required(VERSION 3.5)

project(Interlocked)
find_package(Pcf REQUIRED)
add_executable(Interlocked Interlocked.cpp)
target_link_libraries(Interlocked Pcf.Core)
