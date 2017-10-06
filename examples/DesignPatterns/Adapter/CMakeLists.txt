cmake_minimum_required(VERSION 3.2)

project(Adapter)
find_package(Switch REQUIRED)
add_executable(Adapter Adapter.cpp)
target_link_libraries(Adapter Switch.System)
