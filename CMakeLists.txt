cmake_minimum_required(VERSION 3.5)

project(Pcf VERSION 0.2.0)

option(BUILD_CORE_INTEGRATION_TESTS "Build Core integration tests" OFF)
option(BUILD_CORE_MANUAL_TESTS "Build Core manual tests" ON)
option(BUILD_CORE_UNIT_TESTS "Build Core unit tests" ON)
option(BUILD_DRAWING_UNIT_TESTS "Build Drawing unit tests" ON)
option(BUILD_FORMS_MANUAL_TESTS "Build Forms manual tests" ON)
option(BUILD_FORMS_UNIT_TESTS "Build Forms unit tests" ON)
option(BUILD_FORMS_WITH_FLTK "ON Build Pcf.Froms with FLTK; otherwise won native interface" OFF)
option(BUILD_FORMS_WITH_GTK "ON Build Pcf.Froms with GTK; otherwise won native interface" OFF)
option(BUILD_TUNIT_UNIT_TESTS "Build TUnit unit tests" ON)

enable_testing()

if (BUILD_FORMS_WITH_FLTK AND BUILD_FORMS_WITH_GTK)
  message(FATAL_ERROR "Use BUILD_FORMS_WITH_FLTK or BUILD_FORMS_WITH_GTK (or none for native interface) but not both")
elseif (BUILD_FORMS_WITH_FLTK)
  add_definitions(-D__use_fltk_interface__)
elseif (BUILD_FORMS_WITH_GTK)
  add_definitions(-D__use_gtk_interface__)
else()
  add_definitions(-D__use_native_interface__)
endif()

if (APPLE)
  SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/D_WINSOCK_DEPRECATED_NO_WARNINGS /DCURL_STATICLIB /DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /w4003 /wd4100 /wd4127 /wd4132 /wd4133 /wd4189 /wd4244 /wd4245 /wd4310 /wd4312 /wd4355 /wd4389 /wd4456 /wd4458 /wd4505 /wd4510 /wd4512 /wd4610 /wd4701 /wd4702 /wd4706 /wd4996")
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else ()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif ()

include(PcfDependencies.cmake)

add_subdirectory("Core")
add_subdirectory("Drawing")
add_subdirectory("Forms")
add_subdirectory("TUnit")
add_subdirectory("TUnit.Main")
add_subdirectory("Pcf")

install(EXPORT Pcf DESTINATION cmake)
install(FILES PcfConfig.cmake PcfDependencies.cmake DESTINATION cmake)

find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Pcf.Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
  add_custom_target(documentation ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} COMMENT "Generating API documentation with Doxygen" VERBATIM)
endif(DOXYGEN_FOUND)
