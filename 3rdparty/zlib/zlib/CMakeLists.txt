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

add_library(${PROJECT_NAME} STATIC ${include_files} ${source_files})
target_include_directories(zlib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
target_link_libraries(${PROJECT_NAME} ${STANDARD_LINK_LIBRARIES})
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_HOME_DIRECTORY}/../lib/$<TARGET_FILE_NAME:${PROJECT_NAME}>)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(FILES zconf.h zlib.h DESTINATION include)
if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION bin CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb" DESTINATION bin CONFIGURATIONS Release OPTIONAL)
endif()
