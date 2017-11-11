cmake_minimum_required(VERSION 3.2)

project(zlib VERSION 1.2.8)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

add_subdirectory(zlib)

#install(EXPORT zlib DESTINATION cmake)  
install(FILES zlibConfig.cmake DESTINATION cmake)
