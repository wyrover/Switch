cmake_minimum_required(VERSION 3.2)

project(Prototype)
find_package(Switch REQUIRED)
add_executable(Prototype Prototype.cpp)
target_link_libraries(Prototype Switch.Core)
