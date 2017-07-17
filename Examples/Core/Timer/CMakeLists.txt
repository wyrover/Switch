cmake_minimum_required(VERSION 3.2)

project(Timer)
find_package(Pcf REQUIRED)
add_executable(Timer Timer.cpp)
target_link_libraries(Timer Pcf.Core)
