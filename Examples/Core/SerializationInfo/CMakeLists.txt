cmake_minimum_required(VERSION 3.2)

project(SerializationInfo)
find_package(Pcf REQUIRED)
add_executable(SerializationInfo SerializationInfo.cpp)
target_link_libraries(SerializationInfo Pcf.Core)
