cmake_minimum_required(VERSION 3.2)

project(DirectoryGetFiles)
find_package(Switch REQUIRED)
add_executable(DirectoryGetFiles DirectoryGetFiles.cpp)
target_link_libraries(DirectoryGetFiles Switch.System)
