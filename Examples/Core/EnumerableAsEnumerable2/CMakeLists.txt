cmake_minimum_required(VERSION 3.2)

project(EnumerableAsEnumerable2)
find_package(Pcf REQUIRED)
add_executable(EnumerableAsEnumerable2 EnumerableAsEnumerable2.cpp)
target_link_libraries(EnumerableAsEnumerable2 Pcf.Core)
