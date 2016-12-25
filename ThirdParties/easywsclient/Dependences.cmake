if (APPLE OR UNIX)
  set(HOME $ENV{HOME})
elseif (MSVC)
  set(HOME $ENV{HOMEDRIVE}$ENV{HOMEPATH} CACHE PATH "Home path")
endif()
set(CMAKE_INSTALL_PREFIX "${HOME}/Libraries")

macro(FindPackage PACKAGENAME REVISIONNUMBER)
  #Add dependences in files
  list(FIND REPOSITORY_DEPENDENCES "${PACKAGENAME} ${REVISIONNUMBER}" PACKAGE_FOUND_IN_REPOSITORY_DEPENDENCES)
  if (PACKAGE_FOUND_IN_REPOSITORY_DEPENDENCES EQUAL -1)
    if (${PACKAGENAME}_FOUND)
      file(APPEND ${CMAKE_BINARY_DIR}/Dependences.txt "${PACKAGENAME};${REVISIONNUMBER};${CMAKE_CURRENT_LIST_FILE};${PLATFORM_NAME};not used\n")
      message(FATAL_ERROR "Package ${PACKAGENAME} ${REVISIONNUMBER} won't be used as another version of this package is already used!")
    else ()    
      # Search in the repository 
      set(${PACKAGENAME}_DIR "${CMAKE_INSTALL_PREFIX}/${PLATFORM_NAME}/${PACKAGENAME}/${REVISIONNUMBER}/cmake")
      find_package(${PACKAGENAME} QUIET PATH_SUFFIXES "${PLATFORM_NAME}/${PACKAGENAME}/${REVISIONNUMBER}/cmake")  
      
      # The package has been found in the local repository
      if (${PACKAGENAME}_FOUND)
        #message(STATUS "Package ${PACKAGENAME} found in local repository (${CMAKE_FIND_ROOT_PATH})")  
        file(APPEND ${CMAKE_BINARY_DIR}/Dependences.txt "${PACKAGENAME};${REVISIONNUMBER};${CMAKE_CURRENT_LIST_FILE};${PLATFORM_NAME};used\n")
        set(${PACKAGENAME}_DIR "${CMAKE_INSTALL_PREFIX}/${PLATFORM_NAME}/${PACKAGENAME}/${REVISIONNUMBER}/cmake" CACHE PATH "${PACKAGENAME} path" FORCE)
      endif ()  
    endif ()

    if (${PACKAGENAME}_FOUND)
      list(APPEND REPOSITORY_DEPENDENCES "${PACKAGENAME} ${REVISIONNUMBER}")
    else ()
      message(WARNING "Package ${PACKAGENAME} not found !!!")        
    endif ()
  endif ()
endmacro()

#FindPackage(MyLib 1.0.0)
