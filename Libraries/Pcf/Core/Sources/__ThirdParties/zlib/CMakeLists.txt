cmake_minimum_required(VERSION 3.0.2)

project(zlib VERSION 1.2.8)
 
if(APPLE)
  SET(CMAKE_C_FLAGS "-Wno-deprecated")
elseif(UNIX)
  SET(CMAKE_C_FLAGS "-Wno-implicit-function-declaration")
elseif(MSVC)
  set(CMAKE_C_FLAGS_DEBUG          "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_MINSIZEREL     "/MT /O1 /Ob1 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELEASE        "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
  set(CMAKE_C_FLAGS_RELWITHDEBINFO "/MT /MP /Oy- /Zi /O2 /Ob1 /Oy- /D NDEBUG /DRELEASE")
endif()

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

add_subdirectory(zlib)

#install(EXPORT zlib DESTINATION cmake)  
#install(FILES zlibConfig.cmake DESTINATION cmake)
