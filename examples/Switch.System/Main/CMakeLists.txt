cmake_minimum_required(VERSION 3.2)

project(Main)
find_package(Switch REQUIRED)
add_executable(Main Main.cpp)
target_link_libraries(Main Switch.System)
