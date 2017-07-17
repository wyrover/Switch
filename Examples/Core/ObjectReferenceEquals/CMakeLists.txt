cmake_minimum_required(VERSION 3.2)

project(ObjectReferenceEquals)
find_package(Pcf REQUIRED)
add_executable(ObjectReferenceEquals ObjectReferenceEquals.cpp)
target_link_libraries(ObjectReferenceEquals Pcf.Core)
