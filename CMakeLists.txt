#_______________________________________________________________________________________________________________________
#                                                                                                                Project
cmake_minimum_required(VERSION 3.2)
project(Switch VERSION 0.5.0)
set(PROJECT_BRIEF "Native C++ port of .Net Framework on Windows, macOS and Linux.")
set(PROJECT_AUTHOR gammasoft71)
set(PROJECT_LOGO "${CMAKE_CURRENT_SOURCE_DIR}/docs/Pictures/Switch80x80.png")

#_______________________________________________________________________________________________________________________
#                                                                                                          Build Options
option(BUILD_SWITCH_CORE "Build Switch.Core library" ON)
option(BUILD_SWITCH_SYSTEM "Build Switch.System library" ON)
option(BUILD_SWITCH_SYSTEM_CORE "Build Switch.System.Core library" ON)
option(BUILD_SWITCH_SYSTEM_DRAWING "Build Switch.System.Drawing library" ON)
option(BUILD_SWITCH_SYSTEM_SERVICEMODEL "Build Switch.System.ServiceModel library" ON)
option(BUILD_SWITCH_SYSTEM_WINDOWS_FORMS "Build Switch.System.Windows.Forms library" ON)
option(BUILD_SWITCH_TUNIT_CORE "Build Switch.TUnit.Core library" ON)
option(BUILD_SWITCH_TUNIT_FRAMEWORK "Build Switch.TUnit.Framework library" OFF)
option(BUILD_SWITCH_TUNIT_MAIN "Build Switch.TUnit.Main library" ON)
option(BUILD_TESTS "Build Switch tests" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                                          Tools Options
option(DOWNLOAD_ASTYLE "Download and build astyle from Github" OFF)
option(DOWNLOAD_CPPCHECK "Download and build cppcheck from Github" OFF)
option(DOWNLOAD_DOXYGEN "Download and build doxygen from Github" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                                        Verbose Options
option(ENABLE_VERBOSE "Enable verbose" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                                       Coverage Options
option(ENABLE_COVERAGE "Enable code coverage" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                                   Dynamic test Options
# remarks: For the next three options, enable only one option at a time.
option(ENABLE_ASAN "Enable Google Address Sanitizer" OFF)
option(ENABLE_TSAN "Enable Google Thread Sanitizer" OFF)
option(ENABLE_USAN "Enable Google Undefined Sanitizer" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                          astyle command line arguments
list(APPEND ASTYLE_ARGS
  --style=java
  --lineend=linux
  --indent=spaces=2
  --attach-namespaces
  --attach-classes
  --attach-inlines
  --attach-extern-c
  --attach-closing-while
  --indent-namespaces
  --indent-after-parens
  --indent-preproc-define
  --indent-preproc-cond
  --indent-col1-comments
  --pad-oper
  --pad-comma
  --pad-header
  --unpad-paren
  --align-pointer=type
  --align-reference=type
  --remove-braces
  --keep-one-line-blocks
  --keep-one-line-statements
  --convert-tabs
  --close-templates
  --suffix=none
  --recursive
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${CMAKE_SOURCE_DIR}/src/*.hpp
  ${CMAKE_SOURCE_DIR}/tests/*.cpp
  ${CMAKE_SOURCE_DIR}/tests/*.hpp
  ${CMAKE_SOURCE_DIR}/examples/*.cpp
  )

#_______________________________________________________________________________________________________________________
#                                                                                        cppcheck command line arguments
#--enable=warning,style,performance,portability,unusedFunction
list(APPEND CPPCHECK_ARGS
  --enable=warning,style
  --error-exitcode=1
  -j 8
  --language=c++
  --std=c++14
  --suppressions-list=${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive.txt
  --template='[{file}:{line}]: ({severity}) {{id}} {message}'
  --report-progress
  ${CMAKE_SOURCE_DIR}/src/Switch/src
  ${CMAKE_SOURCE_DIR}/src/Switch.Core/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Core/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Drawing/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.ServiceModel/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Windows.Forms/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.TUnit.Core/src
  ${CMAKE_SOURCE_DIR}/src/Switch.TUnit.Framework/src
  ${CMAKE_SOURCE_DIR}/src/Switch.TUnit.Main/src
  )

#_______________________________________________________________________________________________________________________
#                                                                                                           standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#_______________________________________________________________________________________________________________________
#                                                                                            enable USE_FOLDERS property
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#_______________________________________________________________________________________________________________________
#                                                                                                   coverage build flags
if (ENABLE_COVERAGE AND APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  --coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
elseif(ENABLE_COVERAGE AND UNIX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g ")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                   Google Address Sanitizer build flags
if (ENABLE_ASAN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
  endif()

#_______________________________________________________________________________________________________________________
#                                                                                   Google Address Undefined build flags
elseif (ENABLE_USAN)
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")

#_______________________________________________________________________________________________________________________
#                                                                                      Google Address Thread build flags
elseif (ENABLE_TSAN)
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                      libraries name prefix and postfix
set(CMAKE_DEBUG_POSTFIX d)

#_______________________________________________________________________________________________________________________
#                                                                                                 executable output path
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                   executable extension
if (WIN32)
  set(EXECUTABLE_EXTENSION .exe)
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                      Switch build type
if (CMAKE_BUILD_TYPE)
  set(SWITCH_BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
  set(SWITCH_BUILD_TYPE Debug)
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                install
install(EXPORT Switch DESTINATION cmake)
install(FILES scripts/cmake/SwitchConfig.cmake scripts/cmake/SwitchDependencies.cmake DESTINATION cmake)

#_______________________________________________________________________________________________________________________
#                                                                                                  include CMake modules
#include(CTest)
include(ExternalProject)

#_______________________________________________________________________________________________________________________
#                                                                                                 include Switch modules
include(scripts/cmake/AddCustomTargets.cmake)
include(scripts/cmake/Build3rdParties.cmake)
include(scripts/cmake/BuildSwitchLibraries.cmake)
include(scripts/cmake/BuildSwitchTests.cmake)
include(scripts/cmake/DownloadTools.cmake)
include(scripts/cmake/GetInformations.cmake)
include(scripts/cmake/MakeLibraryProject.cmake)
include(scripts/cmake/MakeTestProject.cmake)
include(scripts/cmake/Print.cmake)
include(scripts/cmake/SwitchDependencies.cmake)
include(scripts/cmake/UpdateVersionNumber.cmake)

#_______________________________________________________________________________________________________________________
#                                                                                                  Update Version Number
UpdateVersionNumber()

#_______________________________________________________________________________________________________________________
#                                                                                                       Get Informations
GetInformations()

#_______________________________________________________________________________________________________________________
#                                                                                                         Download Tools
DownloadTools()

#_______________________________________________________________________________________________________________________
#                                                                                                      Build 3rd parties
Build3rdParties()

#_______________________________________________________________________________________________________________________
#                                                                                                 Build Switch Libraries
BuildSwitchLibraries()

#_______________________________________________________________________________________________________________________
#                                                                                                     Build Switch Tests
BuildSwitchTests()

#_______________________________________________________________________________________________________________________
#                                                                                                     Add Custom Targets
AddCustomTargets()

#_______________________________________________________________________________________________________________________
#                                                                                                                 Legend
print("")
print("(*) embeded version")
print("")
