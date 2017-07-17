cmake_minimum_required(VERSION 3.2)

project(Profile)
find_package(Pcf REQUIRED)
add_executable(Profile Profile.cpp)
target_link_libraries(Profile Pcf.Core)
