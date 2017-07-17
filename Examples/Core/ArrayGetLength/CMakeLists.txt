cmake_minimum_required(VERSION 3.2)

project(ArrayGetLength)
find_package(Pcf REQUIRED)
add_executable(ArrayGetLength ArrayGetLength.cpp)
target_link_libraries(ArrayGetLength Pcf.Core)
