cmake_minimum_required(VERSION 3.2)

project(ObjectToString)
find_package(Switch REQUIRED)
add_executable(ObjectToString ObjectToString.cpp)
target_link_libraries(ObjectToString Switch.Core)
