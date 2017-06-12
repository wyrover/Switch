cmake_minimum_required(VERSION 3.5)

project(EnumerableAgregate)
find_package(Pcf REQUIRED)
add_executable(EnumerableAgregate EnumerableAgregate.cpp)
target_link_libraries(EnumerableAgregate Pcf.Core)
