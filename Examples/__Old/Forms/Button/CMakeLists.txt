cmake_minimum_required(VERSION 3.5)

project(Button)

set(CMAKE_CXX_STANDARD 14)

find_package(Pcf REQUIRED)
add_executable(${PROJECT_NAME} Button.cpp)
target_link_libraries(${PROJECT_NAME} ${Pcf_LIBRARIES})
