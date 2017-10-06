cmake_minimum_required(VERSION 3.2)

project(Nameof)
find_package(Switch REQUIRED)
add_executable(Nameof Nameof.cpp)
target_link_libraries(Nameof Switch.System)
