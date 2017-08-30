cmake_minimum_required(VERSION 3.2)

project(Facade)
find_package(Switch REQUIRED)
add_executable(Facade Facade.cpp)
target_link_libraries(Facade Switch.Core)
