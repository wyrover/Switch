cmake_minimum_required(VERSION 3.2)

project(Boolean5)
find_package(Pcf REQUIRED)
add_executable(Boolean5 Boolean5.cpp)
target_link_libraries(Boolean5 Pcf.Core)
