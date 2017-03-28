cmake_minimum_required(VERSION 3.5)

project(ArrayIndexOf)
find_package(Pcf REQUIRED)
add_executable(ArrayIndexOf ArrayIndexOf.cpp)
target_link_libraries(ArrayIndexOf Pcf.Core)
