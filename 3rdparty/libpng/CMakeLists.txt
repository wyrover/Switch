cmake_minimum_required(VERSION 3.2)

project(libpng VERSION 1.5.10)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

# source files for png
set(PNG_SRCS
  pngget.c
  pngrio.c
  pngwrite.c
  png.c
  pngmem.c
  pngrtran.c
  pngtrans.c
  pngwtran.c
  pngerror.c
  pngpread.c
  pngrutil.c
  pngwutil.c
  pngread.c
  pngset.c
  pngwio.c
)

set(Includes_SRCS
  png.h
  pngconf.h
  pngdebug.h
  pnginfo.h
  pnglibconf.h
  pngpriv.h
  pngstruct.h
)

add_library(libpng STATIC "${PNG_SRCS}")
target_include_directories(libpng PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_link_libraries(libpng ${ZLIB_LIBRARIES})
add_custom_command(TARGET libpng POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:libpng> ${CMAKE_HOME_DIRECTORY}/../lib/$<TARGET_FILE_NAME:libpng>)

#install(EXPORT libpng DESTINATION cmake)  
install(FILES libpngConfig.cmake DESTINATION cmake)
install(TARGETS libpng EXPORT Switch DESTINATION lib)
install(FILES png.h pngconf.h pnglibconf.h DESTINATION include)
if(MSVC)
  target_compile_options(libpng PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:libpng>/libpng${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(libpng PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:libpng>/libpng.pdb>")
  install(FILES "$<TARGET_FILE_DIR:libpng>/libpng${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:libpng>/libpng.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
