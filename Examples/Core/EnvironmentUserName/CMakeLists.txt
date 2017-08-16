cmake_minimum_required(VERSION 3.2)

project(EnvironmentUserName)
find_package(Pcf REQUIRED)
add_executable(EnvironmentUserName EnvironmentUserName.cpp)
target_link_libraries(EnvironmentUserName Pcf.Core)
