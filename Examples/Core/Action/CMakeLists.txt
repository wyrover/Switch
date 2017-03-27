cmake_minimum_required(VERSION 3.5)

project(Action)
find_package(Pcf REQUIRED)
add_executable(Action Action.cpp)
target_link_libraries(Action Pcf.Core)
