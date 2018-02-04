#_________________________________________________________________________________________
#                                                                          include modules
include(${CMAKE_CURRENT_LIST_DIR}/Switch.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/SwitchDependencies.cmake)

#_________________________________________________________________________________________
#                                                                    set include directory
get_filename_component(SWITCH_INCLUDE_DIRS 
  "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)

#_________________________________________________________________________________________
#                                                                  set libraries directory
get_filename_component(SWITCH_LIBRARIES_DIRS 
  "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

#_________________________________________________________________________________________
#                                                                    add external packages
find_package(call_stack REQUIRED)
find_package(CURL REQUIRED)
find_package(easywsclient REQUIRED)
find_package(GTest REQUIRED)
find_package(JPEG REQUIRED)
find_package(RS232 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)

#_________________________________________________________________________________________
#                                                                        add compile flags
if (MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /bigobj")
endif()

#_________________________________________________________________________________________
#                                                                            set libraries
set(SWITCH_LIBRARY Switch.TUnit.Core Switch.System.Windows.Forms
  Switch.System.Drawing Switch.System Switch.Core)
set(SWITCH_LIBRARIES ${SWITCH_LIBRARY})
set(SWITCH_WITH_TUNIT_MAIN_LIBRARY Switch.TUnit.Main ${SWITCH_LIBRARIES})
set(SWITCH_WITH_TUNIT_MAIN_LIBRARIES ${SWITCH_WITH_TUNIT_MAIN_LIBRARY})

#_________________________________________________________________________________________
#                                                                                set found
set(Switch_FOUND TRUE)
set(SWITCH_FOUND TRUE)
