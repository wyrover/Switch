cmake_minimum_required(VERSION 3.2)

project(Singleton)
find_package(Pcf REQUIRED)
add_executable(Singleton Singleton.cpp)
target_link_libraries(Singleton Pcf.Core)
