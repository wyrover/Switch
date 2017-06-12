cmake_minimum_required(VERSION 3.5)

project(EventHandler)
find_package(Pcf REQUIRED)
add_executable(EventHandler EventHandler.cpp)
target_link_libraries(EventHandler Pcf.Core)
