cmake_minimum_required(VERSION 3.2)

project(ChainOfResponsability)
find_package(Switch REQUIRED)
add_executable(ChainOfResponsability ChainOfResponsability.cpp)
target_link_libraries(ChainOfResponsability Switch.Core)
