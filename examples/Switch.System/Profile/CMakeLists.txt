cmake_minimum_required(VERSION 3.2)

project(Profile)
find_package(Switch REQUIRED)
add_executable(Profile Profile.cpp)
target_link_libraries(Profile Switch.System)
