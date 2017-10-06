cmake_minimum_required(VERSION 3.2)

project(Hashtable)
find_package(Switch REQUIRED)
add_executable(Hashtable Hashtable.cpp)
target_link_libraries(Hashtable Switch.System)
