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

project(call_srack  VERSION 1.0.0)

set(INCLUDE_FILES
  Sources/call_stack.hpp
  Sources/stack_exception.hpp
  Sources/StackWalker/StackWalker.h 
  Sources/ModuleInformation.h
  Sources/StackFrame.h
  Sources/ThreadInformation.h
  Sources/ProcessInformation.h
)

set(SOURCE_FILES
  Sources/call_stack_gcc.cpp 
  Sources/call_stack_msvc.cpp 
  Sources/StackWalker/StackWalker.cpp
  Sources/ModuleInformation.cpp
  Sources/StackFrame.cpp
  Sources/ThreadInformation.cpp
  Sources/ProcessInformation.cpp
)

source_group(Includes REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\StackWalker REGULAR_EXPRESSION "/Sources/StackWalker/[-_,A-Za-z0-9]+\\.h*")

source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\StackWalker REGULAR_EXPRESSION "/Sources/StackWalker/[-_,A-Za-z0-9]+\\.c*")

add_library(call_stack STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_link_libraries(call_stack ${STANDARD_LINK_LIBRARIES})
target_include_directories(call_stack PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Sources> $<INSTALL_INTERFACE:include>)
set_target_properties(call_stack PROPERTIES FOLDER Pcf/Core/__ThirdParties)

#install(EXPORT call_stack DESTINATION cmake)  
#install(FILES call_stackConfig.cmake DESTINATION cmake)
install(TARGETS call_stack EXPORT Pcf DESTINATION lib)
#install (FILES ${INCLUDE_FILES} DESTINATION include/call_stack)
if(MSVC)
  target_compile_options(call_stack PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:call_stack>/call_stack${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(call_stack PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:call_stack>/call_stack.pdb>")
  install(FILES "$<TARGET_FILE_DIR:call_stack>/call_stack${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:call_stack>/call_stack.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
