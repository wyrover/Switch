cmake_minimum_required(VERSION 3.2)

project(ObjectEquals2)
find_package(Switch REQUIRED)
add_executable(ObjectEquals2 ObjectEquals2.cpp)
target_link_libraries(ObjectEquals2 Switch.System)
