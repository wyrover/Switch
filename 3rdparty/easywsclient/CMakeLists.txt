cmake_minimum_required(VERSION 3.2)

project(easywsclient)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

add_library(easywsclient STATIC easywsclient.hpp easywsclient.cpp)
target_include_directories(easywsclient PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..> $<INSTALL_INTERFACE:include>)

#install(EXPORT easywsclient DESTINATION cmake)  
install(FILES easywsclientConfig.cmake DESTINATION cmake)
install(TARGETS easywsclient EXPORT Switch DESTINATION lib)
install (FILES easywsclient.hpp DESTINATION include/easywsclient)
if(MSVC)
  target_compile_options(easywsclient PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:easywsclient>/easywsclient${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(easywsclient PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:easywsclient>/easywsclient.pdb>")
  install(FILES "$<TARGET_FILE_DIR:easywsclient>/easywsclient${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:easywsclient>/easywsclient.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
