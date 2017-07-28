cmake_minimum_required(VERSION 3.2)

project(AbstractFactory)
find_package(Pcf REQUIRED)
add_executable(AbstractFactory AbstractFactory.cpp)
target_link_libraries(AbstractFactory Pcf.Core)
