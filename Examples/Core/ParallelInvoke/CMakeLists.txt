cmake_minimum_required(VERSION 3.2)

project(ParallelInvoke)
find_package(Pcf REQUIRED)
add_executable(ParallelInvoke ParallelInvoke.cpp)
target_link_libraries(ParallelInvoke Pcf.Core)
