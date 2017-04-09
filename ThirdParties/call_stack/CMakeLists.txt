cmake_minimum_required(VERSION 3.5)

project(call_stack  VERSION 1.0.0)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

set(INCLUDE_FILES
  call_stack/call_stack.hpp
  call_stack/stack_exception.hpp
  call_stack/StackWalker/StackWalker.h 
  call_stack/ModuleInformation.h
  call_stack/StackFrame.h
  call_stack/ThreadInformation.h
  call_stack/ProcessInformation.h
)

set(SOURCE_FILES
  call_stack/call_stack_gcc.cpp 
  call_stack/call_stack_msvc.cpp 
  call_stack/StackWalker/StackWalker.cpp
  call_stack/ModuleInformation.cpp
  call_stack/StackFrame.cpp
  call_stack/ThreadInformation.cpp
  call_stack/ProcessInformation.cpp
)

source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\StackWalker REGULAR_EXPRESSION "/Sources/StackWalker/[-_,A-Za-z0-9]+\\.c*")

add_library(call_stack STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_link_libraries(call_stack)
target_include_directories(call_stack PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)

install(EXPORT call_stack DESTINATION cmake)  
install(FILES call_stackConfig.cmake DESTINATION cmake)
install(TARGETS call_stack EXPORT call_stack DESTINATION lib)
install (FILES ${INCLUDE_FILES} DESTINATION include/call_stack)
if(MSVC)
  target_compile_options(call_stack PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:call_stack>/call_stack${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(call_stack PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:call_stack>/call_stack.pdb>")
  install(FILES "$<TARGET_FILE_DIR:call_stack>/call_stack${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:call_stack>/call_stack.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
