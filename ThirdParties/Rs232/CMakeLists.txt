cmake_minimum_required(VERSION 3.0.2)

project(Rs232 VERSION 2015.10.11)
 
if(PLATFORM_NAME STREQUAL "DESKTOP_OSX64")
  SET(CMAKE_C_FLAGS "-Wno-deprecated")
elseif(MSVC)
  set(CMAKE_C_FLAGS_DEBUG          "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELEASE        "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /MP /Oy- /Zi /O2 /Ob1 /Oy- /D NDEBUG /DRELEASE")
endif()

enable_testing()

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

if (APPLE OR UNIX)
  set(HOME $ENV{HOME})
elseif (MSVC)
  set(HOME $ENV{HOMEDRIVE}$ENV{HOMEPATH} CACHE PATH "Home path")
endif()
set(CMAKE_INSTALL_PREFIX "${HOME}/Libraries/${PLATFORM_NAME}/${PROJECT_NAME}/${PROJECT_VERSION}${INSTALL_REV}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add include files here:
set(includeFiles
./RS-232/rs232.h
)

# Add source files here:
set(sourceFiles
./RS-232/rs232.c
)

#Add include groups here:
source_group(Includes REGULAR_EXPRESSION "/RS-232/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/RS-232/[-_,A-Za-z0-9]+\\.c*")

add_library(Rs232 STATIC ${includeFiles} ${sourceFiles}) 
target_link_libraries(Rs232 ${STANDARD_LINK_LIBRARIES})

target_include_directories(Rs232 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/RS-232> $<INSTALL_INTERFACE:include>)

install(EXPORT Rs232 DESTINATION cmake)  
install(FILES Rs232Config.cmake DESTINATION cmake)
install(TARGETS Rs232 EXPORT Rs232 DESTINATION lib)
install (FILES ${includeFiles} DESTINATION include/Rs232)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:Rs232>/Rs232${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:Rs232>/Rs232.pdb")
  target_compile_options(Rs232 PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(Rs232 PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:Rs232>/Rs232${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Rs232>/Rs232.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
