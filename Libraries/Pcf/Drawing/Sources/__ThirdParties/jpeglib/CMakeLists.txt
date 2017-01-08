cmake_minimum_required(VERSION 3.0.2)

project(jpeglib VERSION 2011.1.16)
 
if(PLATFORM_NAME STREQUAL "DESKTOP_OSX64")
  SET(CMAKE_C_FLAGS "-Wno-deprecated")
elseif(MSVC)
  set(CMAKE_C_FLAGS_DEBUG          "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELEASE        "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /MP /Oy- /Zi /O2 /Ob1 /Oy- /D NDEBUG /DRELEASE")
endif()

set(systemdependent_SRCS jmemnobs.c)

# library object files common to compression and decompression
set(common_SRCS
  jaricom.c
  jcomapi.c
  jutils.c
  jerror.c
  jmemmgr.c
)

# compression library object files
set(compression_SRCS
  jcapimin.c
  jcapistd.c
  jcarith.c
  jctrans.c
  jcparam.c
  jdatadst.c
  jcinit.c
  jcmaster.c
  jcmarker.c
  jcmainct.c
  jcprepct.c
  jccoefct.c
  jccolor.c
  jcsample.c
  jchuff.c
  jcdctmgr.c
  jfdctfst.c
  jfdctflt.c
  jfdctint.c
)

# decompression library object files
set(decompression_SRCS
  jdapimin.c
  jdapistd.c
  jdarith.c
  jdtrans.c
  jdatasrc.c
  jdmaster.c
  jdinput.c
  jdmarker.c
  jdhuff.c
  jdmainct.c
  jdcoefct.c
  jdpostct.c
  jddctmgr.c
  jidctfst.c
  jidctflt.c
  jidctint.c
  jdsample.c
  jdcolor.c
  jquant1.c
  jquant2.c
  jdmerge.c
)

set(Includes_SRCS
  jconfig.h
  jdct.h
  jerror.h
  jinclude.h
  jmemsys.h
  jmorecfg.h
  jpegint.h
  jpeglib.h
  jversion.h
)

list(APPEND BUILD_SRCS "${systemdependent_SRCS};${common_SRCS}")
list(APPEND BUILD_SRCS "${compression_SRCS};${decompression_SRCS}")

if (MSVC)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
endif ()

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

add_library(jpeglib STATIC "${BUILD_SRCS}")
target_include_directories(jpeglib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
set_target_properties(jpeglib PROPERTIES FOLDER Pcf/Drawing/__ThirdParties)

#install(EXPORT jpeglib DESTINATION cmake)  
#install(FILES jpeglibConfig.cmake DESTINATION cmake)
install(TARGETS jpeglib EXPORT Pcf DESTINATION lib)
#install(FILES ${Includes_SRCS} DESTINATION include/jpeglib)

if(MSVC)
  target_compile_options(jpeglib PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:jpeglib>/jpeglib${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(jpeglib PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:jpeglib>/jpeglib.pdb>")
  install(FILES "$<TARGET_FILE_DIR:jpeglib>/jpeglib${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:jpeglib>/jpeglib.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
