cmake_minimum_required(VERSION 3.2)

project(ArrayGetSyncRoot)
find_package(Switch REQUIRED)
add_executable(ArrayGetSyncRoot ArrayGetSyncRoot.cpp)
target_link_libraries(ArrayGetSyncRoot Switch.System)
