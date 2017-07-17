cmake_minimum_required(VERSION 3.2)

project(Main)
find_package(Pcf REQUIRED)
add_executable(Main Main.cpp)
target_link_libraries(Main Pcf.Core)
