cmake_minimum_required(VERSION 3.5)

project(SharedPtr)
find_package(Pcf REQUIRED)
add_executable(SharedPtr SharedPtr.cpp)
target_link_libraries(SharedPtr Pcf.Core)
