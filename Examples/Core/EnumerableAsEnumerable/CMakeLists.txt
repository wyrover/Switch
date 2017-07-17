cmake_minimum_required(VERSION 3.2)

project(EnumerableAsEnumerable)
find_package(Pcf REQUIRED)
add_executable(EnumerableAsEnumerable EnumerableAsEnumerable.cpp)
target_link_libraries(EnumerableAsEnumerable Pcf.Core)
