cmake_minimum_required(VERSION 3.2)

project(Lock)
find_package(Switch REQUIRED)
add_executable(Lock Lock.cpp)
target_link_libraries(Lock Switch.System)
