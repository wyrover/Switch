cmake_minimum_required(VERSION 3.2)

project(Delegate)
find_package(Pcf REQUIRED)
add_executable(Delegate Delegate.cpp)
target_link_libraries(Delegate Pcf.Core)
