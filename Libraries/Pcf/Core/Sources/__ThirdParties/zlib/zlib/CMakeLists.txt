# include files for zlib
set(include_files
crc32.h
deflate.h
gzguts.h
inffast.h
inffixed.h
inflate.h
inftrees.h
trees.h
zconf.h
zconf.in.h
zlib.h
zutil.h 
)

# source files for zlib
set(source_files
adler32.c
compress.c
crc32.c
deflate.c
#example.c
gzlib.c
gzread.c
gzwrite.c
gzclose.c
infback.c
inffast.c
inflate.c
inftrees.c
#minigzip.c
trees.c
uncompr.c
zutil.c 
)

if (MSVC)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1 /wd4996")
  set(CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE /wd4996")
endif ()

if (APPLE)
  set(STANDARD_LINK_LIBRARIES pthread)	
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl pthread rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

add_library(zlib STATIC ${include_files} ${source_files})
target_link_libraries(zlib ${STANDARD_LINK_LIBRARIES})
target_include_directories(zlib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
set_target_properties(zlib PROPERTIES FOLDER Pcf/Core/__ThirdParties)

install(TARGETS zlib EXPORT Pcf DESTINATION lib)
#install(FILES zconf.h zlib.h DESTINATION include/zlib)
if(MSVC)
  target_compile_options(zlib PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:zlib>/zlib${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(zlib PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:zlib>/zlib.pdb>")
  install(FILES "$<TARGET_FILE_DIR:zlib>/zlib${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:zlib>/zlib.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
