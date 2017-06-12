cmake_minimum_required(VERSION 3.5)

project(Process)
find_package(Pcf REQUIRED)
add_executable(Process Process.cpp)
target_link_libraries(Process Pcf.Core)
