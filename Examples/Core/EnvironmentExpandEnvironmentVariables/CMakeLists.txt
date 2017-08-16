cmake_minimum_required(VERSION 3.2)

project(EnvironmentExpandEnvironmentVariables)
find_package(Pcf REQUIRED)
add_executable(EnvironmentExpandEnvironmentVariables EnvironmentExpandEnvironmentVariables.cpp)
target_link_libraries(EnvironmentExpandEnvironmentVariables Pcf.Core)
