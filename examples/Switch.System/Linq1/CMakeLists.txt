cmake_minimum_required(VERSION 3.2)

project(Linq1)
find_package(Switch REQUIRED)
add_executable(Linq1 Linq1.cpp)
target_link_libraries(Linq1 Switch.System)
