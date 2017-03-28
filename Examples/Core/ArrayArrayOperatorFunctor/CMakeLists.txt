cmake_minimum_required(VERSION 3.5)

project(ArrayArrayOperatorFunctor)
find_package(Pcf REQUIRED)
add_executable(ArrayArrayOperatorFunctor ArrayArrayOperatorFunctor.cpp)
target_link_libraries(ArrayArrayOperatorFunctor Pcf.Core)
