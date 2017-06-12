cmake_minimum_required(VERSION 3.5)

project(ObjectGetType)
find_package(Pcf REQUIRED)
add_executable(ObjectGetType ObjectGetType.cpp)
target_link_libraries(ObjectGetType Pcf.Core)
