cmake_minimum_required(VERSION 3.2)

project(Proxy)
find_package(Pcf REQUIRED)
add_executable(Proxy Proxy.cpp)
target_link_libraries(Proxy Pcf.Core)
