cmake_minimum_required(VERSION 3.5)

project(Any)
find_package(Pcf REQUIRED)
add_executable(Any Any.cpp)
target_link_libraries(Any Pcf.Core)
