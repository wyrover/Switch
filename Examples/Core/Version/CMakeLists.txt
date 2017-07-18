cmake_minimum_required(VERSION 3.2)

project(Version)
find_package(Pcf REQUIRED)
add_executable(Version Version.cpp)
target_link_libraries(Version Pcf.Core)
