cmake_minimum_required(VERSION 3.2)

project(Singleton)
find_package(Switch REQUIRED)
add_executable(Singleton Singleton.cpp)
target_link_libraries(Singleton Switch.System)
