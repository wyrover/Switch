cmake_minimum_required(VERSION 3.2)

project(ArrayArrayOperator)
find_package(Switch REQUIRED)
add_executable(ArrayArrayOperator ArrayArrayOperator.cpp)
target_link_libraries(ArrayArrayOperator Switch.System)
