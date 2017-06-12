cmake_minimum_required(VERSION 3.5)

project(EnumerableAgregate2)
find_package(Pcf REQUIRED)
add_executable(EnumerableAgregate2 EnumerableAgregate2.cpp)
target_link_libraries(EnumerableAgregate2 Pcf.Core)
