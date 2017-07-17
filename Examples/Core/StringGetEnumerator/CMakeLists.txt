cmake_minimum_required(VERSION 3.2)

project(StringGetEnumerator)
find_package(Pcf REQUIRED)
add_executable(StringGetEnumerator StringGetEnumerator.cpp)
target_link_libraries(StringGetEnumerator Pcf.Core)
