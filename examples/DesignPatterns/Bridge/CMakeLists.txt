cmake_minimum_required(VERSION 3.2)

project(Bridge)
find_package(Switch REQUIRED)
add_executable(Bridge Bridge.cpp)
target_link_libraries(Bridge Switch.System)
