cmake_minimum_required(VERSION 3.0.2)

project(libcurl VERSION 7.36.0)

set(BUILD_RELEASE_DEBUG_DIRS ON CACHE bool "Set OFF to build each configuration to a separate directory")
set(BUILD_CURL_EXE OFF CACHE bool "Set to ON to build cURL executable.")
set(BUILD_CURL_TESTS OFF CACHE bool "Set to ON to build cURL tests.")
set(CURL_STATICLIB ON CACHE bool "Set to ON to build libcurl with static linking.")
set(CURL_USE_ARES OFF CACHE bool "Set to ON to enable c-ares support")

set(CURL_DISABLE_LDAP ON CACHE bool "disables LDAP")
set(CURL_DISABLE_TELNET ON CACHE bool "disables Telnet")
set(CURL_DISABLE_DICT ON CACHE bool "disables DICT")
set(CURL_DISABLE_FILE  ON CACHE bool "disables FILE")
set(CURL_DISABLE_LDAPS ON CACHE bool "to disable LDAPS")
set(CURL_ZLIB OFF CACHE bool "" FORCE)
set(CMAKE_USE_OPENSSL OFF CACHE bool "" FORCE)
  
if(CYGWIN OR ANDROID OR UNIX OR APPLE)
  set(HAVE_GLIBC_STRERROR_R OFF CACHE bool "" FORCE)
  set(HAVE_GLIBC_STRERROR_R__TRYRUN_OUTPUT OFF CACHE bool "" FORCE)
  set(HAVE_POSIX_STRERROR_R ON CACHE bool "" FORCE)
  set(HAVE_POSIX_STRERROR_R__TRYRUN_OUTPUT OFF CACHE bool "" FORCE)
  set(HAVE_POLL_FINE  OFF CACHE bool "" FORCE)
  set(HAVE_POLL_FINE__TRYRUN_OUTPUT OFF CACHE bool "" FORCE)
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

if (MSVC)
  set(CMAKE_C_FLAGS_DEBUG "/D_DEBUG /DDEBUG /MTd /MP /Oy- /Zi /Od /Zi /Oy- /RTC1")
  set(CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /Oy- /D NDEBUG /DRELEASE")
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_subdirectory(CURL)

if(CMAKE_GENERATOR STREQUAL "Visual Studio 10 Win64" OR CMAKE_GENERATOR STREQUAL "Visual Studio 9 2008 Win64" OR CMAKE_GENERATOR STREQUAL "Visual Studio 11 Win64")
  message("Force x64 for libcurl")
  set_target_properties(libcurl PROPERTIES STATIC_LIBRARY_FLAGS "/machine:x64")
endif()
 
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/CURL/include> $<INSTALL_INTERFACE:include>)
       
install(EXPORT ${PROJECT_NAME} DESTINATION cmake)
install(FILES ${PROJECT_NAME}Config.cmake DESTINATION cmake)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION bin CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb" DESTINATION bin CONFIGURATIONS Release OPTIONAL)
endif()
