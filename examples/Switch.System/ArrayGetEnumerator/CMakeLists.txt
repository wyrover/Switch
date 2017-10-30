cmake_minimum_required(VERSION 3.2)

project(ArrayGetEnumerator)
find_package(Switch REQUIRED)
add_executable(ArrayGetEnumerator ArrayGetEnumerator.cpp)
target_link_libraries(ArrayGetEnumerator Switch.System)
