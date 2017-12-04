cmake_minimum_required(VERSION 3.2)

project(jpeg)
 
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
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

add_library(jpeg STATIC "${BUILD_SRCS}")
target_include_directories(jpeg PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)

#install(EXPORT jpeg DESTINATION cmake)  
install(FILES jpegConfig.cmake DESTINATION cmake)
#install(TARGETS jpeg EXPORT jpeg DESTINATION lib)
install(TARGETS jpeg EXPORT Switch DESTINATION lib)
install(FILES jconfig.h jerror.h jmorecfg.h jpeglib.h DESTINATION include)
if(MSVC)
  target_compile_options(jpeg PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:jpeg>/jpeg${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(jpeg PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:jpeg>/jpeg.pdb>")
  install(FILES "$<TARGET_FILE_DIR:jpeg>/jpeg${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:jpeg>/jpeg.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
