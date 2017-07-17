cmake_minimum_required(VERSION 3.2)

project(UniquePtr)
find_package(Pcf REQUIRED)
add_executable(UniquePtr UniquePtr.cpp)
target_link_libraries(UniquePtr Pcf.Core)
