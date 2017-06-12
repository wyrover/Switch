cmake_minimum_required(VERSION 3.5)

project(ListCopyTo)
find_package(Pcf REQUIRED)
add_executable(ListCopyTo ListCopyTo.cpp)
target_link_libraries(ListCopyTo Pcf.Core)
