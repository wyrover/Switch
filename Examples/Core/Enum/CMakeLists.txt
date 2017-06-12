cmake_minimum_required(VERSION 3.5)

project(Enum)
find_package(Pcf REQUIRED)
add_executable(Enum Enum.cpp)
target_link_libraries(Enum Pcf.Core)
