cmake_minimum_required(VERSION 3.2)

project(Assert)

find_package(Switch REQUIRED)
add_executable(Assert Assert.cpp README.md)
target_link_libraries(${PROJECT_NAME} Switch.TUnit.Main)
