cmake_minimum_required(VERSION 3.2)

project(Mediator)
find_package(Pcf REQUIRED)
add_executable(Mediator Mediator.cpp)
target_link_libraries(Mediator Pcf.Core)
