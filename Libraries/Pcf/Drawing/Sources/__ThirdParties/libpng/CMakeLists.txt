cmake_minimum_required(VERSION 3.0.2)

project(libpng VERSION 1.5.10)
 
if(PLATFORM_NAME STREQUAL "DESKTOP_OSX64")
  SET(CMAKE_C_FLAGS "-Wno-deprecated")
elseif(MSVC)
  set(CMAKE_C_FLAGS_DEBUG          "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELEASE        "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /MP /Oy- /Zi /O2 /Ob1 /Oy- /D NDEBUG /DRELEASE")
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

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

if (MSVC)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
endif ()

add_library(libpng STATIC "${PNG_SRCS}")
target_include_directories(libpng PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_link_libraries(libpng zlib)
set_target_properties(libpng PROPERTIES FOLDER Pcf/Drawing/__ThirdParties)

#install(EXPORT libpng DESTINATION cmake)  
#install(FILES libpngConfig.cmake DESTINATION cmake)
install(TARGETS libpng EXPORT Pcf DESTINATION lib)
#install(FILES ${Includes_SRCS} DESTINATION include/libpng)

if(MSVC)
  target_compile_options(libpng PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:libpng>/libpng${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(libpng PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:libpng>/libpng.pdb>")
  install(FILES "$<TARGET_FILE_DIR:libpng>/libpng${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:libpng>/libpng.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
