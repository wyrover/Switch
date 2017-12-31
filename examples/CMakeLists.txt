#_________________________________________________________________________________________
#                                                                                  Project
cmake_minimum_required(VERSION 3.2)
project(Examples)
set(PROJECT_BRIEF "These examples show how to use Switch.")
set(PROJECT_AUTHOR gammasoft71)

#_________________________________________________________________________________________
#                                                                            Build Options
option(BUILD_DESIGN_PATTERNS_EXAMPLES "Build DesignPatterns examples" ON)
option(BUILD_SWITCH_SYSTEM_EXAMPLES "Build Switch.System examples" ON)
option(BUILD_SWITCH_SYSTEM_DRAWING_EXAMPLES "Build Switch.System.Drawing examples" ON)
option(BUILD_SWITCH_SYSTEM_WINDOWS_FORMS_EXAMPLES "Build SwitchSystem.Windows.Forms examples" ON)
option(BUILD_SWITCH_TUNIT_EXAMPLES "Build Switch.TUnit examples" ON)
option(BUILD_SWITCH_TUNIT_FRAMEWORK_EXAMPLES "Build Switch.TUnit.Framework examples" OFF)

#_________________________________________________________________________________________
#                                                                          Verbose Options
option(ENABLE_VERBOSE "Enable verbose" OFF)

#_________________________________________________________________________________________
#                                                                             standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#_________________________________________________________________________________________
#                                                              enable USE_FOLDERS property
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#_________________________________________________________________________________________
#                                                                   executable output path
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif()

#_________________________________________________________________________________________
#                                                                   include Switch modules
include(../scripts/cmake/GetInformations.cmake)
include(../scripts/cmake/Print.cmake)

#_________________________________________________________________________________________
#                                                                         Get Informations
GetInformations()

#_________________________________________________________________________________________
#                                                                              subdir list
macro(subdirlist RESULT CURRENT_DIR)
  file(GLOB children RELATIVE ${CURRENT_DIR} ${CURRENT_DIR}/*)
  set(dirlist "")
  foreach (child ${children})
    if (IS_DIRECTORY ${CURRENT_DIR}/${child})
      LIST(APPEND dirlist ${child})
    endif ()
  endforeach ()
  set(${RESULT} ${dirlist})
endmacro()

#_________________________________________________________________________________________
#                                                              add subdrirectory childrens
macro(add_subdirectory_childrens CURRENT_DIR)
  subdirlist(SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}")
  foreach (SUBDIR ${SUBDIRS})
    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/${CURRENT_DIR}/${SUBDIR}")
    set_target_properties(${SUBDIR} PROPERTIES FOLDER ${CURRENT_DIR})
  endforeach ()
endmacro ()

#_________________________________________________________________________________________
#                                                           Build Design Patterns examples
print("Generating Switch Examples")
if (BUILD_DESIGN_PATTERNS_EXAMPLES)
  print("  [X] DesignPatterns")
  add_subdirectory_childrens("DesignPatterns")
else()
  print("  [ ] DesignPatterns")
endif()

#_________________________________________________________________________________________
#                                                             Build Switch.System examples
if (BUILD_SWITCH_SYSTEM_EXAMPLES)
  print("  [X] Switch.System")
  add_subdirectory_childrens("Switch.System")
else()
  print("  [ ] Switch.System")
endif()

#_________________________________________________________________________________________
#                                                     Build Switch.System.Drawing examples
if (BUILD_SWITCH_SYSTEM_DRAWING_EXAMPLES)
  print("  [X] Switch.System.Drawing")
  add_subdirectory_childrens("Switch.System.Drawing")
endif()

#_________________________________________________________________________________________
#                                               Build Switch.System.Windows.Forms examples
if (BUILD_SWITCH_SYSTEM_WINDOWS_FORMS_EXAMPLES)
  print("  [X] Switch.System.Windows.Forms")
  add_subdirectory_childrens("Switch.System.Windows.Forms")
else()
  print("  [ ] Switch.System.Windows.Forms")
endif()

#_________________________________________________________________________________________
#                                                              Build Switch.TUnit examples
if (BUILD_SWITCH_TUNIT_EXAMPLES)
  print("  [X] Switch.TUnit")
  add_subdirectory_childrens("Switch.TUnit")
else()
  print("  [ ] Switch.TUnit")
endif()

#_________________________________________________________________________________________
#                                                    Build Switch.TUnit.Framework examples
if (BUILD_SWITCH_TUNIT_FRAMEWORK_EXAMPLES)
  print("  [X] Switch.TUnit.Framework")
  add_subdirectory_childrens("Switch.TUnit.Framework")
else()
  print("  [ ] Switch.TUnit.Framework")
endif()
