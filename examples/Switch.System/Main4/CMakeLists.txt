cmake_minimum_required(VERSION 3.2)

project(Main4)
find_package(Switch REQUIRED)
add_executable(Main4 Main4.cpp)
target_link_libraries(Main4 Switch.System)
