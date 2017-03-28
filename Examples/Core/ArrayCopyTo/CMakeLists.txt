cmake_minimum_required(VERSION 3.5)

project(ArrayCopyTo)
find_package(Pcf REQUIRED)
add_executable(ArrayCopyTo ArrayCopyTo.cpp)
target_link_libraries(ArrayCopyTo Pcf.Core)
