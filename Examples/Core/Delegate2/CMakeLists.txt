cmake_minimum_required(VERSION 3.2)

project(Delegate2)
find_package(Pcf REQUIRED)
add_executable(Delegate2 Delegate2.cpp)
target_link_libraries(Delegate2 Pcf.Core)
