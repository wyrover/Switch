cmake_minimum_required(VERSION 3.0.2)

project(zlib VERSION 1.2.8)
 
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

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

add_subdirectory(zlib)

install(EXPORT zlib DESTINATION cmake)  
install(FILES zlibConfig.cmake DESTINATION cmake)
