cmake_minimum_required(VERSION 3.2)

project(Nullable)
find_package(Pcf REQUIRED)
add_executable(Nullable Nullable.cpp)
target_link_libraries(Nullable Pcf.Core)
