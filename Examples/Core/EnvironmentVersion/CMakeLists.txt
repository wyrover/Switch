cmake_minimum_required(VERSION 3.2)

project(EnvironmentVersion)
find_package(Pcf REQUIRED)
add_executable(EnvironmentVersion EnvironmentVersion.cpp)
target_link_libraries(EnvironmentVersion Pcf.Core)
