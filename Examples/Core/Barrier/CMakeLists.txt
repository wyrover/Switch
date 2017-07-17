cmake_minimum_required(VERSION 3.2)

project(Barrier)
find_package(Pcf REQUIRED)
add_executable(Barrier Barrier.cpp)
target_link_libraries(Barrier Pcf.Core)
