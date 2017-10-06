cmake_minimum_required(VERSION 3.2)

project(Socket)
find_package(Switch REQUIRED)
add_executable(Socket Socket.cpp)
target_link_libraries(Socket Switch.System)
