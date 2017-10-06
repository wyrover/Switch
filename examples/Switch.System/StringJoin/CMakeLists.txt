cmake_minimum_required(VERSION 3.2)

project(StringJoin)
find_package(Switch REQUIRED)
add_executable(StringJoin StringJoin.cpp)
target_link_libraries(StringJoin Switch.System)
