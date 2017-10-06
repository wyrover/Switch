cmake_minimum_required(VERSION 3.2)

project(Nullable)
find_package(Switch REQUIRED)
add_executable(Nullable Nullable.cpp)
target_link_libraries(Nullable Switch.System)
