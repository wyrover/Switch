cmake_minimum_required(VERSION 3.2)

project(ObjectReferenceEquals)
find_package(Switch REQUIRED)
add_executable(ObjectReferenceEquals ObjectReferenceEquals.cpp)
target_link_libraries(ObjectReferenceEquals Switch.Core)
