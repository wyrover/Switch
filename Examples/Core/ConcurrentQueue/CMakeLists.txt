cmake_minimum_required(VERSION 3.0.2)

project(ConcurrentQueue VERSION 1.0.0)
include(../../Dependences.cmake)

if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -WExtra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /wd4100 /wd4127 /wd4132 /wd4133 /wd4189 /wd4244 /wd4245 /wd4310 /wd4312 /wd4355 /wd4389 /wd4456 /wd4458 /wd4505 /wd4510 /wd4512 /wd4610 /wd4701 /wd4702 /wd4706 /wd4996")
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

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Add include files here:
set(INCLUDE_FILES
)

# Add source files here:
set(SOURCES_FILES
./Sources/${PROJECT_NAME}.cpp
)

#Add source groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_executable(${PROJECT_NAME} ${INCLUDE_FILES} ${SOURCES_FILES})
target_link_libraries(${PROJECT_NAME} Pcf)
