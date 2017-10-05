cmake_minimum_required(VERSION 3.2)

project(EnvironmentSystemDirectory)
find_package(Switch REQUIRED)
add_executable(EnvironmentSystemDirectory EnvironmentSystemDirectory.cpp)
target_link_libraries(EnvironmentSystemDirectory Switch.Core)
