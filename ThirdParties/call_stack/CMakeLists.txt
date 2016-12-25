cmake_minimum_required(VERSION 3.0.2)

project(call_stack VERSION 1.0.0)
 
if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -WExtra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /wd4100 /wd4312 /wd4355 /wd4456 /wd4458")
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
  ./Sources/call_stack.hpp
  ./Sources/stack_exception.hpp
  ./Sources/StackWalker/StackWalker.h 
  ./Sources/ModuleInformation.h
  ./Sources/StackFrame.h
  ./Sources/ThreadInformation.h
  ./Sources/ProcessInformation.h
)

# Add source files here:
set(sourceFiles
  ./Sources/call_stack_gcc.cpp 
  ./Sources/call_stack_msvc.cpp 
  ./Sources/StackWalker/StackWalker.cpp
  ./Sources/ModuleInformation.cpp
  ./Sources/StackFrame.cpp
  ./Sources/ThreadInformation.cpp
  ./Sources/ProcessInformation.cpp
)

#Add include groups here:
source_group(Includes REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\StackWalker REGULAR_EXPRESSION "/Sources/StackWalker/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\StackWalker REGULAR_EXPRESSION "/Sources/StackWalker/[-_,A-Za-z0-9]+\\.c*")

add_library(call_stack STATIC ${includeFiles} ${sourceFiles})
target_link_libraries(call_stack ${STANDARD_LINK_LIBRARIES})

target_include_directories(call_stack PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Sources> $<INSTALL_INTERFACE:include>)

install(EXPORT call_stack DESTINATION cmake)  
install(FILES call_stackConfig.cmake DESTINATION cmake)
install(TARGETS call_stack EXPORT call_stack DESTINATION lib)
install(FILES ${includeFiles}  DESTINATION include/call_stack)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:call_stack>/call_stack${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:call_stack>/call_stack.pdb")
  target_compile_options(call_stack PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(call_stack PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:call_stack>/call_stack${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:call_stack>/call_stack.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
