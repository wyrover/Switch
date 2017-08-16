cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetFolderPath)
find_package(Pcf REQUIRED)
add_executable(EnvironmentGetFolderPath EnvironmentGetFolderPath.cpp)
target_link_libraries(EnvironmentGetFolderPath Pcf.Core)
