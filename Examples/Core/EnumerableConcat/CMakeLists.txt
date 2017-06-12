cmake_minimum_required(VERSION 3.5)

project(EnumerableConcat)
find_package(Pcf REQUIRED)
add_executable(EnumerableConcat EnumerableConcat.cpp)
target_link_libraries(EnumerableConcat Pcf.Core)
