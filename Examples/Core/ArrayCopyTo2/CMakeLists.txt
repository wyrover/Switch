cmake_minimum_required(VERSION 3.2)

project(ArrayCopyTo2)
find_package(Pcf REQUIRED)
add_executable(ArrayCopyTo2 ArrayCopyTo2.cpp)
target_link_libraries(ArrayCopyTo2 Pcf.Core)
