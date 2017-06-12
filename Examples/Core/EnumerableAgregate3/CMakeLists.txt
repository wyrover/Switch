cmake_minimum_required(VERSION 3.5)

project(EnumerableAgregate3)
find_package(Pcf REQUIRED)
add_executable(EnumerableAgregate3 EnumerableAgregate3.cpp)
target_link_libraries(EnumerableAgregate3 Pcf.Core)
