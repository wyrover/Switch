cmake_minimum_required(VERSION 3.2)

project(Linq4)
find_package(Switch REQUIRED)
add_executable(Linq4 Linq4.cpp)
target_link_libraries(Linq4 Switch.System)
