cmake_minimum_required(VERSION 3.5)

project(LinqAgregate)
find_package(Pcf REQUIRED)
add_executable(LinqAgregate LinqAgregate.cpp)
target_link_libraries(LinqAgregate Pcf.Core)
