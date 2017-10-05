cmake_minimum_required(VERSION 3.2)

project(ArrayGetSyncRoot)
find_package(Switch REQUIRED)
add_executable(ArrayGetSyncRoot ArrayGetSyncRoot.cpp README.md)
target_link_libraries(ArrayGetSyncRoot Switch.Core)
