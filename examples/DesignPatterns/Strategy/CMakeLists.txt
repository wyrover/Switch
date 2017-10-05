cmake_minimum_required(VERSION 3.2)

project(Strategy)
find_package(Switch REQUIRED)
add_executable(Strategy Strategy.cpp)
target_link_libraries(Strategy Switch.Core)
