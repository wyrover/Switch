cmake_minimum_required(VERSION 3.0.2)

project(libpng VERSION 1.5.10)
 
include(Dependences.cmake)

if(PLATFORM_NAME STREQUAL "DESKTOP_OSX64")
  SET(CMAKE_C_FLAGS "-Wno-deprecated")
elseif(MSVC)
  set(CMAKE_C_FLAGS_DEBUG          "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELEASE        "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /MP /Oy- /Zi /O2 /Ob1 /Oy- /D NDEBUG /DRELEASE")
endif()

enable_testing()

if (APPLE OR UNIX)
  set(HOME $ENV{HOME})
elseif (MSVC)
  set(HOME $ENV{HOMEDRIVE}$ENV{HOMEPATH} CACHE PATH "Home path")
endif()
set(CMAKE_INSTALL_PREFIX "${HOME}/Libraries/${PLATFORM_NAME}/${PROJECT_NAME}/${PROJECT_VERSION}${INSTALL_REV}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

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

install(EXPORT libpng DESTINATION cmake)  
install(FILES libpngConfig.cmake DESTINATION cmake)
install(TARGETS libpng EXPORT libpng DESTINATION lib)
install(FILES ${Includes_SRCS} DESTINATION include/libpng)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:libpng>/libpng${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:libpng>/libpng.pdb")
  target_compile_options(libpng PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(libpng PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:libpng>/libpng${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:libpng>/libpng.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
