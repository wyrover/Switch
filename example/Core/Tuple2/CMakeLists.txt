cmake_minimum_required(VERSION 3.2)

project(Tuple2)
find_package(Switch REQUIRED)
add_executable(Tuple2 Tuple2.cpp)
target_link_libraries(Tuple2 Switch.Core)
