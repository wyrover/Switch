cmake_minimum_required(VERSION 3.2)

project(Main4)
find_package(Pcf REQUIRED)
add_executable(Main4 Main4.cpp)
target_link_libraries(Main4 Pcf.Core)
