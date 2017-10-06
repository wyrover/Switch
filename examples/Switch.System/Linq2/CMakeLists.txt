cmake_minimum_required(VERSION 3.2)

project(Linq2)
find_package(Switch REQUIRED)
add_executable(Linq2 Linq2.cpp)
target_link_libraries(Linq2 Switch.System)
