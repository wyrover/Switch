cmake_minimum_required(VERSION 3.2)

project(SerializationInfo)
find_package(Switch REQUIRED)
add_executable(SerializationInfo SerializationInfo.cpp)
target_link_libraries(SerializationInfo Switch.Core)
