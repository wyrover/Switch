cmake_minimum_required(VERSION 3.5)

project(Trace)
find_package(Pcf REQUIRED)
add_executable(Trace Trace.cpp)
target_link_libraries(Trace Pcf.Core)
