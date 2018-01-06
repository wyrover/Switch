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
#                                                         set STANDARD_CORE_LINK_LIBRARIES
if(MSVC)
  set(STANDARD_CORE_LINK_LIBRARIES ws2_32 iphlpapi rpcrt4)
elseif (APPLE)
  set(STANDARD_CORE_LINK_LIBRARIES dl ncurses)
elseif(UNIX)
  set(STANDARD_CORE_LINK_LIBRARIES dl rt uuid)
endif ()

#_________________________________________________________________________________________
#                                                      set STANDARD_GRAPHIC_LINK_LIBRARIES
if(MSVC)
  set(STANDARD_GRAPHIC_LINK_LIBRARIES uxtheme comctl32)
elseif (APPLE)
  set(STANDARD_GRAPHIC_LINK_LIBRARIES)
elseif(UNIX)
  set(STANDARD_GRAPHIC_LINK_LIBRARIES ${GTKMM_LIBRARIES})
endif ()

#_________________________________________________________________________________________
#                                                                      set COCOA_FRAMEWORK
if (APPLE)
  set(COCOA_FRAMEWORK "-framework Carbon -framework Cocoa -framework ApplicationServices -framework Foundation")
else ()
  set(COCOA_FRAMEWORK)
endif ()
