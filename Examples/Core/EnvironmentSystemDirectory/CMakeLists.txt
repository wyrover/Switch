cmake_minimum_required(VERSION 3.2)

project(EnvironmentSystemDirectory)
find_package(Pcf REQUIRED)
add_executable(EnvironmentSystemDirectory EnvironmentSystemDirectory.cpp)
target_link_libraries(EnvironmentSystemDirectory Pcf.Core)
