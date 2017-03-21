cmake_minimum_required(VERSION 3.5)

project(Array2)

set(CMAKE_CXX_STANDARD 14)

find_package(Pcf REQUIRED)
add_executable(${PROJECT_NAME} Array2.cpp)
target_link_libraries(${PROJECT_NAME} ${Pcf_LIBRARIES})
