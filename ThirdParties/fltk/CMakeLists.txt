cmake_minimum_required(VERSION 3.0.2)
 
project(fltk VERSION 1.3.4)
 
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -WExtra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /Zi /W1 /wd4100 /wd4312 /wd4355 /wd4456 /wd4458 /wd4996")
  set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Od /Zi /RTC1 /D_DEBUG /DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /Gy /O2 /Oi /GL- /DNDEBUG /DRELEASE")
endif ()

if (APPLE)
  set(STANDARD_LINK_LIBRARIES pthread)
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl pthread rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)
endif ()

if (APPLE OR UNIX)
  set(HOME $ENV{HOME})
elseif (MSVC)
  set(HOME $ENV{HOMEDRIVE}$ENV{HOMEPATH} CACHE PATH "Home path")
endif()
set(CMAKE_INSTALL_PREFIX "${HOME}/Libraries/${PLATFORM_NAME}/${PROJECT_NAME}/${PROJECT_VERSION}${INSTALL_REV}")

#set(OPTION_BUILD_EXAMPLES OFF)

add_subdirectory(${PROJECT_NAME})
 
#####################################################################################################    
# Comment the last line of fltk/CMakeLists.txt :
# include(CMake/install.cmake)
#
# Add line at last to fltk/src/CMakeLists.txt :
# install(TARGETS fltk fltk_forms fltk_images fltk_gl EXPORT fltk DESTINATION lib/${COMPILER_SUBDIR})
#
# Add line at the end of file to fltk/jpeg/CMakeLists.txt :
# install(TARGETS fltk_jpeg EXPORT fltk DESTINATION lib/${COMPILER_SUBDIR})
#
# Add line at the end of file to fltk/png/CMakeLists.txt :
# install(TARGETS fltk_png EXPORT fltk DESTINATION lib/${COMPILER_SUBDIR})

# Add line at the end of file to fltk/zlib/CMakeLists.txt :
# install(TARGETS fltk_z EXPORT fltk DESTINATION lib/${COMPILER_SUBDIR})
#
# Comment the last lines of fltk/fulid/CMakeLists.txt :
# install(TARGETS fluid
#     EXPORT FLTK-Targets
#     RUNTIME DESTINATION bin
#     LIBRARY DESTINATION lib
#     ARCHIVE DESTINATION lib
#     )
#####################################################################################################    

target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
install(FILES ${PROJECT_NAME}Config.cmake DESTINATION cmake) 
#install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib) 
install(DIRECTORY "./${PROJECT_NAME}/FL/."  DESTINATION include/FL PATTERN ".svn" EXCLUDE)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
