cmake_minimum_required(VERSION 3.2)

project(TaskDelay)
find_package(Switch REQUIRED)
add_executable(TaskDelay TaskDelay.cpp)
target_link_libraries(TaskDelay Switch.System)
