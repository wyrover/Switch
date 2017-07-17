cmake_minimum_required(VERSION 3.2)

project(BitArray)
find_package(Pcf REQUIRED)
add_executable(BitArray BitArray.cpp)
target_link_libraries(BitArray Pcf.Core)
