#_______________________________________________________________________________________________________________________
#                                                                                                                Project
cmake_minimum_required(VERSION 3.2)
project(Switch VERSION 0.5.0)
set(PROJECT_DESCRIPTION "Native C++ port of .Net Framework on Windows, macOS and Linux.")

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

#_______________________________________________________________________________________________________________________
#                                                                                                          Tests Options
option(BUILD_TESTS "Build tests" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                                       Download Options
option(DOWNLOAD_ASTYLE "Download and build astyle from Github" OFF)
option(DOWNLOAD_CPPCHECK "Download and build cppcheck from Github" OFF)
option(DOWNLOAD_DOXYGEN "Download and build doxygen from Github" OFF)

#_______________________________________________________________________________________________________________________
#                                                                                                         Enable Options
option(ENABLE_VERBOSE "Enable verbose" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)
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
  --fill-empty-lines
  --align-pointer=type
  --align-reference=type
  --remove-braces
  --keep-one-line-blocks
  --keep-one-line-statements
  --convert-tabs
  --close-templates
  --suffix=none
  --recursive
  ${CMAKE_SOURCE_DIR}/examples/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
  ${CMAKE_SOURCE_DIR}/src/*.hpp
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/tests/*.hpp
  ${CMAKE_SOURCE_DIR}/tests/*.cpp
  )

#_______________________________________________________________________________________________________________________
#                                                                                        cppcheck command line arguments
list(APPEND CPPCHECK_ARGS
  --enable=warning,style,performance,portability,unusedFunction
  --error-exitcode=1
  -I ${CMAKE_SOURCE_DIR}/src/Switch/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.Core/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System.Core/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System.Drawing/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System.ServiceModel/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System.Windows.Forms/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System.Unit.Core/include
  -I ${CMAKE_SOURCE_DIR}/src/Switch.System.Unit.framework/include
  -j 8
  --language=c++
  --std=c++14
  --suppressions-list=${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive.txt
  --template='[{file}:{line}]: ({severity}) {{id}} {message}'
  --verbose
  ${CMAKE_SOURCE_DIR}/src/Switch/src
  ${CMAKE_SOURCE_DIR}/src/Switch.Core/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Core/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Drawing/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.ServiceModel/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Windows.Forms/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Unit.Core/src
  ${CMAKE_SOURCE_DIR}/src/Switch.System.Unit.framework/src
  ${CMAKE_SOURCE_DIR}/examples
  ${CMAKE_SOURCE_DIR}/tests
  )

#_______________________________________________________________________________________________________________________
#                                                                                                           standard C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
if(ENABLE_ASAN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=leak")
  endif()
endif()

#_______________________________________________________________________________________________________________________
#                                                                                   Google Address Undefined build flags
if(ENABLE_USAN)
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                      Google Address Thread build flags
if(ENABLE_TSAN)
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#_______________________________________________________________________________________________________________________
#                                                                                        library name prefix and postfix
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
#                                                                                                       print if verbose
macro(print)
  if (ENABLE_VERBOSE)
  message(STATUS ${ARGN})
  endif()
endmacro()

#_______________________________________________________________________________________________________________________
#                                                                                                        include modules
include(ExternalProject)
include(scripts/cmake/MakeLibraryProject.cmake)
include(scripts/cmake/MakeTestProject.cmake)
include(scripts/cmake/SwitchDependencies.cmake)

#_______________________________________________________________________________________________________________________
#                                                                                                 Version number updater
file(READ src/Switch.Core/src/Native/EnvironmentVersionApi.cpp ENVIRONMENT_VERSION_API)
string(FIND "${ENVIRONMENT_VERSION_API}" "${Switch_VERSION}" STRING_FOUND)
if (${STRING_FOUND} EQUAL -1)
  print("")
  print("--------------------------------")
  print("--- Version number changed ! ---")
  print("--------------------------------")
  print("")
  file(WRITE src/Switch.Core/src/Native/EnvironmentVersionApi.cpp "#include \"Api.hpp\"\n\nSystem::Version Native::EnvironmentApi::GetVersion() {\n  return System::Version::Parse(\"${Switch_VERSION}\");\n}\n")
  file(WRITE .appveyor.yml "version: ${Switch_VERSION}.{build}\nimage: Visual Studio 2017\nenvironment:\n  matrix:\n  - SWITCH_BUILD_WIN32: true\n  - SWITCH_BUILD_WIN64: true\nbuild_script:\n- cmd: scripts\\appveyor\\build_vs2017.bat\ntest_script:\n- cmd: scripts\\appveyor\\test.bat\n")
  file(WRITE install.sh "export switch_version=${Switch_VERSION}\nscripts/install/install.sh \"$@\"\n")
  file(WRITE install.bat "@set switch_version=${Switch_VERSION}\n@call scripts\\install\\install.bat %*\n")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                           Informations
print("Informations:")
print("  CMake version [${CMAKE_VERSION}]")
print("  System [${CMAKE_SYSTEM}]")
print("  Compiler [${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}]")
print("  Build type [${CMAKE_BUILD_TYPE}]")
print("  Debug postfix [${CMAKE_DEBUG_POSTFIX}]")
if (UNIX)
  print("  Code coverage [${ENABLE_COVERAGE}]")
else()
  print("  Code coverage [NOT AVAIBLE]")
endif()
if (UNIX)
  print("  Google Address Sanitizer [${ENABLE_ASAN}]")
else()
  print("  Google Address Sanitizer [NOT AVAIBLE]")
endif()
if (UNIX)
  print("  Google Undefined Sanitizer [${ENABLE_USAN}]")
else()
  print("  Google Undefined Sanitizer [NOT AVAIBLE]")
endif()
if (UNIX)
  print("  Google Thread Sanitizer [${ENABLE_TSAN}]")
else()
  print("  Google Thread Sanitizer [NOT AVAIBLE]")
endif()
print("  Install prefix [${CMAKE_INSTALL_PREFIX}]")
print("  Output path [${EXECUTABLE_OUTPUT_PATH}]")
print("  Executable extension [${EXECUTABLE_EXTENSION}]")

#_______________________________________________________________________________________________________________________
#                                                                                                                  Tools
print("Tools:")

#_______________________________________________________________________________________________________________________
#                                                                                                                    Git
find_package(Git REQUIRED QUIET)
if (Git_FOUND)
  print("  [X] Git ${GIT_VERSION_STRING}")
else()
  print("  [ ] Git")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                 astyle
if (DOWNLOAD_ASTYLE)
  print("  [X] astyle v1.2 (*)")
  ExternalProject_Add(astyle GIT_REPOSITORY https://github.com/Bareflank/astyle.git GIT_TAG v1.2 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
  set(ASTYLE_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/astyle${EXECUTABLE_EXTENSION})
  set(ASTYLE_PROJECT astyle)
else()
  set(ASTYLE_EXECUTABLE astyle${EXECUTABLE_EXTENSION})
  print("  [ ] astyle v1.2")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                               cppcheck
if (DOWNLOAD_CPPCHECK)
  print("  [X] cppcheck 1.81 (*)")
  ExternalProject_Add(cppcheck GIT_REPOSITORY https://github.com/danmar/cppcheck.git GIT_TAG 1.81 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
  set(CPPCHECK_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/cppcheck${EXECUTABLE_EXTENSION})
  set(CPPCHECK_PROJECT cppcheck)
else()
  set(CPPCHECK_EXECUTABLE cppcheck${EXECUTABLE_EXTENSION})
  print("  [ ] cppcheck 1.81")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                doxygen
find_package(Doxygen QUIET)
if (Doxygen_FOUND)
  print("  [X] Doxygen ${DOXYGEN_VERSION}")
elseif(DOWNLOAD_DOXYGEN)
  print("  [X] Doxygen 1.8.13 (*)")
  ExternalProject_Add(doxygen GIT_REPOSITORY https://github.com/doxygen/doxygen.git GIT_TAG Release_1_8_13 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
  set(Doxygen_FOUND TRUE)
  set(DOXYGEN_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/doxygen${EXECUTABLE_EXTENSION})
  set(DOXYGEN_PROJECT doxygen)
else()
  set(DOXYGEN_EXECUTABLE doxygen${EXECUTABLE_EXTENSION})
  print("  [ ] Doxygen 1.8.13")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                            3rd parties
print("3rd parties")

#_______________________________________________________________________________________________________________________
#                                                                                                             call_stack
if (BUILD_SWITCH_CORE)
  find_package(CALL_STACK QUIET)
  if (CALL_STACK_FOUND)
    print("  [X] call_stack")
  else()
    print("  [X] call_stack master (*)")
    add_subdirectory(3rdparty/call_stack)
    set(CALL_STACK_LIBRARY call_stack)
    set(CALL_STACK_LIBRARIES ${CALL_STACK_LIBRARY})
  endif()
else()
  print("  [ ] call_stack")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                           easywsclient
if (BUILD_SWITCH_CORE)
  find_package(EASYWSCLIENT QUIET)
  if (EASYWSCLIENT_FOUND)
    print("  [X] easywsclient")
  else()
    print("  [X] easywsclient master (*)")
    add_subdirectory(3rdparty/easywsclient)
    set(EASYWSCLIENT_LIBRARY easywsclient)
    set(EASYWSCLIENT_LIBRARIES ${EASYWSCLIENT_LIBRARY})
  endif()
else()
  print("  [ ] easywsclient")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                  RS232
if (BUILD_SWITCH_CORE)
  find_package(RS232 QUIET)
  if (RS232_FOUND)
    print("  [X] RS232")
  else()
    print("  [X] RS232 master (*)")
    add_subdirectory(3rdparty/RS-232)
  endif()
else()
  print("  [ ] RS232")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                   ZLIB
if (BUILD_SWITCH_CORE)
  find_package(ZLIB QUIET)
  if (ZLIB_FOUND)
    print("  [X] ZLIB ${ZLIB_VERSION_STRING}")
  else()
    print("  [X] ZLIB 1.2.8 (*)")
    add_subdirectory(3rdparty/zlib)
    set(ZLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/zlib/zlib")
    set(ZLIB_INCLUDE_DIRS ${ZLIB_INCLUDE_DIR})
    set(ZLIB_LIBRARY zlib)
    set(ZLIB_LIBRARIES ${ZLIB_LIBRARY})
  endif()
else()
  print("  [ ] ZLIB")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                   CURL
if (BUILD_SWITCH_SYSTEM)
  find_package(CURL QUIET)
  if (CURL_FOUND)
    print("  [X] curl ${CURL_VERSION_STRING}")
  else()
    print("  [X] curl 7.53.0 (*)")
    add_subdirectory(3rdparty/curl)
    set(CURL_LIBRARIES libcurl)
    set(CURL_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/curl/include" "${CMAKE_CURRENT_BINARY_DIR}/3rdparty/curl/include/curl")
    include_directories(${CURL_INCLUDE_DIRS})
  endif()
else()
  print("  [ ] curl")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                   jpeg
if (BUILD_SWITCH_SYSTEM_DRAWING)
  find_package(JPEG)
  if (JPEG_FOUND)
    print("  [X] JPEG")
  else()
    print("  [X] JPEG master (*)")
    add_subdirectory(3rdparty/jpeg)
    set(JPEG_LIBRARY jpeg)
    set(JPEG_LIBRARIES ${JPEG_LIBRARY})
  endif()
else()
  print("  [ ] JPEG")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                 libpng
if (BUILD_SWITCH_SYSTEM_DRAWING)
  find_package(PNG QUIET)
  if (PNG_FOUND)
    print("  [X] PNG  ${PNG_VERSION_STRING}")
  else()
    print("  [X] PNG 1.6.34 (*)")
    add_subdirectory(3rdparty/libpng)
    set(PNG_LIBRARIES png_static)
    set(PNG_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/libpng" "${CMAKE_CURRENT_BINARY_DIR}/3rdparty/libpng")
    include_directories(${PNG_INCLUDE_DIRS})
  endif()
else()
  print("  [ ] PNG")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                  GTest
if (BUILD_SWITCH_TUNIT_CORE OR BUILD_TESTS)
  find_package(GTEST QUIET)
  if (GTEST_FOUND)
    print("  [X] GTest")
  else()
    print("  [X] gtest 1.8.0 (*)")
    add_subdirectory(3rdparty/googletest)
    set(GTEST_LIBRARY gtest)
    set(GTEST_LIBRARIES ${GTEST_LIBRARY})
    set(GTEST_MAIN_LIBRARY gtest_main)
    set(GTEST_MAIN_LIBRARIES ${GTEST_MAIN_LIBRARY})
  endif()
endif()


#_______________________________________________________________________________________________________________________
#                                                                                                            Switch Init
print("Switch ${Switch_VERSION}")
file(WRITE src/Switch/include/Switch/Switch.hpp "#pragma once\n\n")

#_______________________________________________________________________________________________________________________
#                                                                                                                 Switch
print("  [X] Switch")
add_subdirectory("src/Switch")

#_______________________________________________________________________________________________________________________
#                                                                                                            Switch.Core
if (BUILD_SWITCH_CORE)
  print("  [X] Switch.Core")
  add_subdirectory("src/Switch.Core")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.Core\"\n")
else()
  print("  [ ] Switch.Core")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                          Switch.System
if (BUILD_SWITCH_SYSTEM)
  print("  [X] Switch.System")
  add_subdirectory("src/Switch.System")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System\"\n")
else()
  print("  [ ] Switch.System")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                     Switch.System.Core
if (BUILD_SWITCH_SYSTEM_CORE)
  print("  [X] Switch.System.Core")
  add_subdirectory("src/Switch.System.Core")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Core\"\n")
else()
  print("  [ ] Switch.System.Core")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                  Switch.System.Drawing
if (BUILD_SWITCH_SYSTEM_DRAWING)
  print("  [X] Switch.System.Drawing")
  add_subdirectory("src/Switch.System.Drawing")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Drawing\"\n")
else()
  print("  [ ] Switch.System.Drawing")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                             Switch.System.ServiceModel
if (BUILD_SWITCH_SYSTEM_SERVICEMODEL)
  print("  [X] Switch.System.ServiceModel")
  add_subdirectory("src/Switch.System.ServiceModel")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.ServiceModel\"\n")
else()
  print("  [ ] Switch.System.ServiceModel")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                            Switch.System.Windows.Forms
if (BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
  print("  [X] Switch.System.Windows.Forms")
  add_subdirectory("src/Switch.System.Windows.Forms")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Windows.Forms\"\n")
else()
  print("  [ ] Switch.System.Windows.Forms")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                      Switch.TUnit.Core
if (BUILD_SWITCH_TUNIT_CORE)
  print("  [X] Switch.TUnit.Core")
  add_subdirectory("src/Switch.TUnit.Core")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.TUnit.Core\"\n")
else()
  print("  [ ] Switch.TUnit.Core")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                 Switch.TUnit.Framework
if (BUILD_SWITCH_TUNIT_FRAMEWORK)
  print("  [X] Switch.TUnit.Framework")
  add_subdirectory("src/Switch.TUnit.Framework")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.TUnit.Framework\"\n")
else()
  print("  [ ] Switch.TUnit.Framework")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                      Switch.TUnit.Main
if (BUILD_SWITCH_TUNIT_MAIN)
  print("  [X] Switch.TUnit.Main")
  add_subdirectory("src/Switch.TUnit.Main")
else()
  print("  [ ] Switch.TUnit.Main")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                           Switch Tests
print("Switch Tests")
if (BUILD_TESTS)
  enable_testing()
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                Switch.Core.ManualTests
if (BUILD_TESTS AND BUILD_SWITCH_CORE)
  print("  [X] Switch.Core.ManualTests")
  add_subdirectory("tests/Switch.Core.ManualTests")
else()
  print("  [ ] Switch.Core.ManualTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                  Switch.Core.UnitTests
if (BUILD_TESTS AND BUILD_SWITCH_CORE)
  print("  [X] Switch.Core.UnitTests")
  add_subdirectory("tests/Switch.Core.UnitTests")
else()
  print("  [ ] Switch.Core.UnitTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                              Switch.System.ManualTests
if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM)
  print("  [X] Switch.System.ManualTests")
  add_subdirectory("tests/Switch.System.ManualTests")
else()
  print("  [ ] Switch.System.ManualTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                Switch.System.UnitTests
if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM)
  print("  [X] Switch.System.UnitTests")
  add_subdirectory("tests/Switch.System.UnitTests")
else()
  print("  [ ] Switch.System.UnitTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                      Switch.System.Drawing.ManualTests
if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_DRAWING)
  print("  [X] Switch.System.Drawing.ManualTests")
  add_subdirectory("tests/Switch.System.Drawing.ManualTests")
else()
  print("  [ ] Switch.System.Drawing.ManualTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                        Switch.System.Drawing.UnitTests
if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_DRAWING)
  print("  [X] Switch.System.Drawing.UnitTests")
  add_subdirectory("tests/Switch.System.Drawing.UnitTests")
else()
  print("  [ ] Switch.System.Drawing.UnitTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                Switch.System.Windows.Forms.ManualTests
if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
  print("  [X] Switch.System.Windows.Forms.ManualTests")
  add_subdirectory("tests/Switch.System.Windows.Forms.ManualTests")
else()
  print("  [ ] Switch.System.Windows.Forms.ManualTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                  Switch.System.Windows.Forms.UnitTests
if (BUILD_TESTS AND BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
  print("  [X] Switch.System.Windows.Forms.UnitTests")
  add_subdirectory("tests/Switch.System.Windows.Forms.UnitTests")
else()
  print("  [ ] Switch.System.Windows.Forms.UnitTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                          Switch.TUnit.Core.ManualTests
if (BUILD_TESTS AND BUILD_SWITCH_TUNIT_CORE)
  print("  [X] Switch.TUnit.ManualTests")
  add_subdirectory("tests/Switch.TUnit.ManualTests")
else()
  print("  [ ] Switch.TUnit.ManualTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                            Switch.TUnit.Core.UnitTests
if (BUILD_TESTS AND BUILD_SWITCH_TUNIT_CORE)
  print("  [X] Switch.TUnit.Core.UnitTests")
  add_subdirectory("tests/Switch.TUnit.UnitTests")
else()
  print("  [ ] Switch.TUnit.Core.UnitTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                     Switch.TUnit.Framework.ManualTests
if (BUILD_TESTS AND BUILD_SWITCH_TUNIT_FRAMEWORK)
  print("  [X] Switch.TUnit.Framework.ManualTests")
  add_subdirectory("tests/Switch.TUnit.Framework.ManualTests")
else()
  print("  [ ] Switch.TUnit.Framework.ManualTests")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                                install
install(EXPORT Switch DESTINATION cmake)
install(FILES scripts/cmake/SwitchConfig.cmake scripts/cmake/SwitchDependencies.cmake DESTINATION cmake)

#_______________________________________________________________________________________________________________________
#                                                                                                         Custom Targets
print("Custom Targets:")

#_______________________________________________________________________________________________________________________
#                                                                                                             Switch.All
print("  [X] ${PROJECT_NAME}.All")
if (WIN32)
  add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
else(UNIX)
  add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" -- -j8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                           Switch.Check
print("  [X] ${PROJECT_NAME}.Check")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive.txt ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive.txt @ONLY)
add_custom_target(${PROJECT_NAME}.Check COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

#_______________________________________________________________________________________________________________________
#                                                                                                          Switch.Format
print("  [X] ${PROJECT_NAME}.Format")
add_custom_target(${PROJECT_NAME}.Format COMMAND ${ASTYLE_EXECUTABLE} ${ASTYLE_ARGS} COMMENT "running astyle" DEPENDS ${ASTYLE_PROJECT})

#_______________________________________________________________________________________________________________________
#                                                                                                        Switch.Gitcheck
print("  [X] ${PROJECT_NAME}.GitCheck")
add_custom_target(${PROJECT_NAME}.GitCheck COMMAND git diff --check HEAD^ COMMENT "running git check")

#_______________________________________________________________________________________________________________________
#                                                                                                         Switch.Install
print("  [X] ${PROJECT_NAME}.Install")
if (WIN32)
  add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
else(UNIX)
  add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install -- -j8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
endif()

#_______________________________________________________________________________________________________________________
#                                                                                                  Switch.ReferenceGuide
print("  [X] ${PROJECT_NAME}.ReferenceGuide")
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.doxygen.txt ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt @ONLY)
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide)
add_custom_target(${PROJECT_NAME}.ReferenceGuide ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide COMMENT "Doxygen Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)

#_______________________________________________________________________________________________________________________
#                                                                                                           Switch.Tests
print("  [X] ${PROJECT_NAME}.Tests")
add_custom_target(${PROJECT_NAME}.Tests COMMAND ctest --output-on-failure -C ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME}.All)

#_______________________________________________________________________________________________________________________
#                                                                                                                    End
print("")
print("(*) embeded version")
print("")
