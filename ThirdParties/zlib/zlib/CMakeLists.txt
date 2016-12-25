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

if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /wd4100 /wd4127 /wd4132 /wd4133 /wd4189 /wd4244 /wd4245 /wd4310 /wd4312 /wd4355 /wd4389 /wd4456 /wd4458 /wd4505 /wd4510 /wd4512 /wd4610 /wd4701 /wd4702 /wd4706 /wd4996")
  set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Od /Zi /RTC1 /D_DEBUG /DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /Gy /O2 /Oi /GL- /DNDEBUG /DRELEASE")
endif ()

add_library(${PROJECT_NAME} STATIC ${include_files} ${source_files})

if (APPLE)
  set(STANDARD_LINK_LIBRARIES pthread)	
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl pthread rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

target_include_directories(zlib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} ${STANDARD_LINK_LIBRARIES})

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(FILES zconf.h zlib.h DESTINATION include/zlib)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION bin CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb" DESTINATION bin CONFIGURATIONS Release OPTIONAL)
endif()
