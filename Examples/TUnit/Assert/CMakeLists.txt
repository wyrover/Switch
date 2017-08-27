cmake_minimum_required(VERSION 3.2)

project(Assert)

find_package(Pcf REQUIRED)
add_executable(Assert Assert.cpp)
target_link_libraries(${PROJECT_NAME} Pcf.TUnit.Main)
