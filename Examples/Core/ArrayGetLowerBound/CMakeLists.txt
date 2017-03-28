cmake_minimum_required(VERSION 3.5)

project(ArrayGetLowerBound)
find_package(Pcf REQUIRED)
add_executable(ArrayGetLowerBound ArrayGetLowerBound.cpp)
target_link_libraries(ArrayGetLowerBound Pcf.Core)
