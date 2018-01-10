#_________________________________________________________________________________________
#                                                                             standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#_________________________________________________________________________________________
#                                                                    add external packages
find_package(Threads REQUIRED)

if(NOT APPLE AND UNIX)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(GTKMM gtkmm-3.0)
  if(NOT GTKMM_FOUND)
    message(FATAL_ERROR "gtkmm-3.0 not found!")
  endif()
  include_directories(${GTKMM_INCLUDE_DIRS})
  link_directories(${GTKMM_LIBRARY_DIRS})
endif ()

#_________________________________________________________________________________________
#                                                                           set SWITCH_GUI
if(MSVC)
  set(SWITCH_GUI WIN32)
elseif (APPLE)
  set(SWITCH_GUI MACOSX_BUNDLE)
elseif(UNIX)
  set(SWITCH_GUI)
endif ()

#_________________________________________________________________________________________
#                                                           set SWITCH_CORE_LINK_LIBRARIES
if(MSVC)
  set(SWITCH_CORE_LINK_LIBRARIES ws2_32 iphlpapi rpcrt4)
elseif (APPLE)
  set(SWITCH_CORE_LINK_LIBRARIES dl)
elseif(UNIX)
  set(SWITCH_CORE_LINK_LIBRARIES dl rt uuid)
endif ()

#_________________________________________________________________________________________
#                                                        set SWITCH_SYSTEM_LINK_FRAMEWORKS
if (APPLE)
  set(SWITCH_SYSTEM_LINK_FRAMEWORKS "-framework Cocoa -framework Foundation")
else ()
  set(SWITCH_SYSTEM_LINK_FRAMEWORKS)
endif ()

#_________________________________________________________________________________________
#                                                 set SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES
if(MSVC)
  set(SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES uxtheme comctl32)
elseif (APPLE)
  set(SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES)
elseif(UNIX)
  set(SWITCH_SYSTEM_DRAWING_LINK_LIBRARIES ${GTKMM_LIBRARIES})
endif ()
