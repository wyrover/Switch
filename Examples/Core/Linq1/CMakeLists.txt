cmake_minimum_required(VERSION 3.5)

project(Linq1)
find_package(Pcf REQUIRED)
add_executable(Linq1 Linq1.cpp)
target_link_libraries(Linq1 Pcf.Core)
