cmake_minimum_required(VERSION 3.2)

project(TupleCreate)
find_package(Switch REQUIRED)
add_executable(TupleCreate TupleCreate.cpp)
target_link_libraries(TupleCreate Switch.Core)
