cmake_minimum_required(VERSION 3.5)

project(EnumerableCast)
find_package(Pcf REQUIRED)
add_executable(EnumerableCast EnumerableCast.cpp)
target_link_libraries(EnumerableCast Pcf.Core)
