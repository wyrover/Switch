cmake_minimum_required(VERSION 3.2)

project(ObjectMemberwiseClone)
find_package(Pcf REQUIRED)
add_executable(ObjectMemberwiseClone ObjectMemberwiseClone.cpp)
target_link_libraries(ObjectMemberwiseClone Pcf.Core)
