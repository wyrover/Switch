cmake_minimum_required(VERSION 3.2)

project(Main2)
find_package(Switch REQUIRED)
add_executable(Main2 Main2.cpp)
target_link_libraries(Main2 Switch.System)
