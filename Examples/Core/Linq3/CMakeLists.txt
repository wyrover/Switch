cmake_minimum_required(VERSION 3.2)

project(Linq3)
find_package(Pcf REQUIRED)
add_executable(Linq3 Linq3.cpp)
target_link_libraries(Linq3 Pcf.Core)
