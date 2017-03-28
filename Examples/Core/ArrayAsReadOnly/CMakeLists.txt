cmake_minimum_required(VERSION 3.5)

project(ArrayAsReadOnly)
find_package(Pcf REQUIRED)
add_executable(ArrayAsReadOnly ArrayAsReadOnly.cpp)
target_link_libraries(ArrayAsReadOnly Pcf.Core)
