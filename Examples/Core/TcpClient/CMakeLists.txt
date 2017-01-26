cmake_minimum_required(VERSION 3.5)

project(TcpClient)

set(CMAKE_CXX_STANDARD 14)

find_package(Pcf)
add_executable(${PROJECT_NAME} Sources/${PROJECT_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} ${Pcf_LIBRARIES})
