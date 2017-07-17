cmake_minimum_required(VERSION 3.2)

project(Unused)
find_package(Pcf REQUIRED)
add_executable(Unused Unused.cpp)
target_link_libraries(Unused Pcf.Core)
