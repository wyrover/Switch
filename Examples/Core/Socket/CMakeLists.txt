cmake_minimum_required(VERSION 3.5)

project(Socket)
find_package(Pcf REQUIRED)
add_executable(Socket Socket.cpp)
target_link_libraries(Socket Pcf.Core)
