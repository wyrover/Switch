cmake_minimum_required(VERSION 3.2)

project(As)
find_package(Switch REQUIRED)
add_executable(As As.cpp)
target_link_libraries(As Switch.System)
