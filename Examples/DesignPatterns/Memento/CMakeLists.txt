cmake_minimum_required(VERSION 3.2)

project(Memento)
find_package(Pcf REQUIRED)
add_executable(Memento Memento.cpp)
target_link_libraries(Memento Pcf.Core)
