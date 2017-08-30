cmake_minimum_required(VERSION 3.2)

project(Mediator)
find_package(Switch REQUIRED)
add_executable(Mediator Mediator.cpp)
target_link_libraries(Mediator Switch.Core)
