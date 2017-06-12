cmake_minimum_required(VERSION 3.5)

project(EnumerableToArray)
find_package(Pcf REQUIRED)
add_executable(EnumerableToArray EnumerableToArray.cpp)
target_link_libraries(EnumerableToArray Pcf.Core)
