cmake_minimum_required(VERSION 3.2)

project(ArrayArrayOperator)
find_package(Pcf REQUIRED)
add_executable(ArrayArrayOperator ArrayArrayOperator.cpp)
target_link_libraries(ArrayArrayOperator Pcf.Core)
