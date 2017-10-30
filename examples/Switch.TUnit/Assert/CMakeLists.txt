cmake_minimum_required(VERSION 3.2)

project(Assert)

find_package(Switch REQUIRED)
add_executable(Assert Assert.cpp)
target_link_libraries(Assert Switch.TUnit.Main)
