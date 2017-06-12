cmake_minimum_required(VERSION 3.5)

project(ObjectToString)
find_package(Pcf REQUIRED)
add_executable(ObjectToString ObjectToString.cpp)
target_link_libraries(ObjectToString Pcf.Core)
