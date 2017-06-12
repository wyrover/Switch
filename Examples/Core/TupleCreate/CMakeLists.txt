cmake_minimum_required(VERSION 3.5)

project(TupleCreate)
find_package(Pcf REQUIRED)
add_executable(TupleCreate TupleCreate.cpp)
target_link_libraries(TupleCreate Pcf.Core)
