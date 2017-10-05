cmake_minimum_required(VERSION 3.2)

project(ArrayArrayOperatorFunctor)
find_package(Switch REQUIRED)
add_executable(ArrayArrayOperatorFunctor ArrayArrayOperatorFunctor.cpp README.md)
target_link_libraries(ArrayArrayOperatorFunctor Switch.Core)
