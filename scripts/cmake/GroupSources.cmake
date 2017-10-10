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
