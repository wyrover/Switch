cmake_minimum_required(VERSION 3.5)

project(As)
find_package(Pcf REQUIRED)
add_executable(As As.cpp)
target_link_libraries(As Pcf.Core)
