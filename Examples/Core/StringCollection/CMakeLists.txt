cmake_minimum_required(VERSION 3.2)

project(StringCollection)
find_package(Pcf REQUIRED)
add_executable(StringCollection StringCollection.cpp)
target_link_libraries(StringCollection Pcf.Core)
