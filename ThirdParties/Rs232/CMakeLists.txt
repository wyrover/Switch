cmake_minimum_required(VERSION 3.5)

project(Rs232)
 
if(PLATFORM_NAME STREQUAL "DESKTOP_OSX64")
  SET(CMAKE_C_FLAGS "-Wno-deprecated")
elseif(MSVC)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /MP /Oy- /Zi /Od /Zi /Oy- /RTC1 /wd4996")
  set(CMAKE_C_FLAGS_RELEASE "/O2 /Ob2 /Oy- /D NDEBUG /DRELEASE /wd4996")
endif()

add_library(Rs232 STATIC Rs232/rs232.h Rs232/rs232.c) 
target_include_directories(Rs232 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)

install(EXPORT Rs232 DESTINATION cmake)  
install(FILES Rs232Config.cmake DESTINATION cmake)
install(TARGETS Rs232 EXPORT Rs232 DESTINATION lib)
install (FILES Rs232/rs232.h DESTINATION include/Rs232)
if(MSVC)
  target_compile_options(Rs232 PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Rs232>/Rs232${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Rs232 PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Rs232>/Rs232.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Rs232>/Rs232${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Rs232>/Rs232.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
