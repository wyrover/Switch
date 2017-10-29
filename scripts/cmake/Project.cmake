# brief: Create source groups from specified directory and child directies for all child files.
# param: mainDir The directory where you want create source groups.
# remarks: This macro is recursive if child is directory too.  
macro(GroupSources mainDir)
  file(GLOB children RELATIVE ${PROJECT_SOURCE_DIR}/${mainDir} ${PROJECT_SOURCE_DIR}/${mainDir}/*)
  foreach(child ${children})
    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/${mainDir}/${child})
      GroupSources(${mainDir}/${child})
    else()
      string(REPLACE "/" "\\" groupName ${mainDir})
      string(REPLACE ".\\" "" groupName ${groupName})
      if (${groupName} STREQUAL ".")
        set(groupName "")        
      endif()
      source_group(${groupName} FILES ${PROJECT_SOURCE_DIR}/${mainDir}/${child})
    endif()
  endforeach()
endmacro()

macro(MakeProject)
  file(GLOB_RECURSE SOURCE_FILES "*.hpp" "*.cpp")

  if (APPLE)
    file(GLOB_RECURSE COCOA_SOURCE_FILES "*.mm")
  endif ()

  GroupSources(.)

  add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES} ${COCOA_SOURCE_FILES})
  target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
  target_link_libraries(${PROJECT_NAME} ${LINK_LIBRARIES})
  set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER src)
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_HOME_DIRECTORY}/lib/$<TARGET_FILE_NAME:${PROJECT_NAME}>)

  install(TARGETS ${PROJECT_NAME} EXPORT Switch DESTINATION lib)

  if (EXISTS include/Switch)
    install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
  endif()

  if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb>")
    target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb>")
    install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
    install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
  endif()
endmacro()