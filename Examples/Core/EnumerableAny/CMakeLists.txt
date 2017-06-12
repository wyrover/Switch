cmake_minimum_required(VERSION 3.5)

project(EnumerableAny)
find_package(Pcf REQUIRED)
add_executable(EnumerableAny EnumerableAny.cpp)
target_link_libraries(EnumerableAny Pcf.Core)
