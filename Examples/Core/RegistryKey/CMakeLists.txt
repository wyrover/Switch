cmake_minimum_required(VERSION 3.2)

project(RegistryKey)
find_package(Pcf REQUIRED)
add_executable(RegistryKey RegistryKey.cpp)
target_link_libraries(RegistryKey Pcf.Core)
