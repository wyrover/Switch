cmake_minimum_required(VERSION 3.2)

project(ArrayLength)
find_package(Pcf REQUIRED)
add_executable(ArrayLength ArrayLength.cpp)
target_link_libraries(ArrayLength Pcf.Core)
