cmake_minimum_required(VERSION 3.2)

project(EnvironmentVersion)
find_package(Switch REQUIRED)
add_executable(EnvironmentVersion EnvironmentVersion.cpp)
target_link_libraries(EnvironmentVersion Switch.Core)
