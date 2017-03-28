cmake_minimum_required(VERSION 3.5)

project(ArrayConstructor)
find_package(Pcf REQUIRED)
add_executable(ArrayConstructor ArrayConstructor.cpp)
target_link_libraries(ArrayConstructor Pcf.Core)
