cmake_minimum_required(VERSION 3.5)

project(ArrayGetEnumerator)
find_package(Pcf REQUIRED)
add_executable(ArrayGetEnumerator ArrayGetEnumerator.cpp)
target_link_libraries(ArrayGetEnumerator Pcf.Core)
