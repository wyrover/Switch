cmake_minimum_required(VERSION 3.2)

project(Switch VERSION 0.4.1)
set(PROJECT_DESCRIPTION "Native C++ port of .Net Framework on Windows, macOS and Linux.")

# options default value
option(BUILD_SWITCH_CORE "Build Switch.Core library" ON)
option(BUILD_SWITCH_SYSTEM "Build Switch.System library" ON)
option(BUILD_SWITCH_SYSTEM_CORE "Build Switch.System.Core library" ON)
option(BUILD_SWITCH_SYSTEM_DRAWING "Build Switch.System.Drawing library" ON)
option(BUILD_SWITCH_SYSTEM_SERVICEMODEL "Build Switch.System.ServiceModel library" ON)
option(BUILD_SWITCH_SYSTEM_WINDOWS_FORMS "Build Switch.System.Windows.Forms library" ON)
option(BUILD_SWITCH_TUNIT_CORE "Build Switch.TUnit.Core library" ON)
option(BUILD_SWITCH_TUNIT_FRAMEWORK "Build Switch.TUnit.Framework library" OFF)
option(BUILD_SWITCH_TUNIT_MAIN "Build Switch.TUnit.Main library" ON)
option(DOWNLOAD_ASTYLE "Download and build astyle from Github" OFF)
option(DOWNLOAD_CPPCHECK "Download and build cppcheck from Github" OFF)
option(BUILD_TESTS "Build tests" OFF)
option(ENABLE_COVERAGE "Enable code coverage" OFF)
option(ENABLE_ASAN "Enable Google Address Sanitizer" OFF)
option(ENABLE_TSAN "Enable Google Thread Sanitizer" OFF)
option(ENABLE_USAN "Enable Google Undefined Sanitizer" OFF)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set coverage flags
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

# set Google Address Sanitizer
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

# set Google Undefined Sanitizer
if(ENABLE_USAN)
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
endif()

# set Google Thread Sanitizer
if(ENABLE_TSAN)
  if (NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fuse-ld=gold")
  endif()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# set CMAKE_DEBUG_POSTFIX if not set
if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

# set executable output path
if ("${CMAKE_BUILD_TYPE}" STREQUAL "")
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
else()
  set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})
endif()

if (WIN32 STREQUAL "1")
  set(EXECUTABLE_EXTENSION .exe)
endif()

if (CMAKE_BUILD_TYPE)
  set(SWITCH_BUILD_TYPE ${CMAKE_BUILD_TYPE})
else()
  set(SWITCH_BUILD_TYPE Debug)
endif()

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

# include modules
include(ExternalProject)
include(scripts/cmake/MakeLibraryProject.cmake)
include(scripts/cmake/MakeTestProject.cmake)
include(scripts/cmake/SwitchDependencies.cmake)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.cppcheck_false_positive.txt ${CMAKE_CURRENT_BINARY_DIR}/cppcheck_false_positive.txt @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/.doxygen.txt ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt @ONLY)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide)

file(READ src/Switch.Core/src/Native/EnvironmentVersionApi.cpp ENVIRONMENT_VERSION_API)
string(FIND "${ENVIRONMENT_VERSION_API}" "${Switch_VERSION}" STRING_FOUND)
if (${STRING_FOUND} EQUAL -1)
  message(STATUS "--------------------------------")
  message(STATUS "--- Version number changed ! ---")
  message(STATUS "--------------------------------")
  file(WRITE src/Switch.Core/src/Native/EnvironmentVersionApi.cpp "#include \"Api.hpp\"\n\nSystem::Version Native::EnvironmentApi::GetVersion() {\n  return System::Version::Parse(\"${Switch_VERSION}\");\n}\n")
  file(WRITE .appveyor.yml "version: ${Switch_VERSION}.{build}\nimage: Visual Studio 2017\nenvironment:\n  matrix:\n  - SWITCH_BUILD_WIN32: true\n  - SWITCH_BUILD_WIN64: true\nbuild_script:\n- cmd: scripts\\appveyor\\build_vs2017.bat\ntest_script:\n- cmd: scripts\\appveyor\\test.bat\n")
  file(WRITE install.sh "export switch_version=${Switch_VERSION}\nscripts/install/install.sh \"$@\"\n")
  file(WRITE install.bat "@set switch_version=${Switch_VERSION}\n@call scripts\\install\\install.bat %*\n")
  file(WRITE src/Switch/include/Switch/Switch.hpp "#pragma once\n\n")
endif()

message(STATUS "Informations")
message(STATUS "  CMake version [${CMAKE_VERSION}]")
message(STATUS "  System [${CMAKE_SYSTEM}]")
message(STATUS "  Compiler [${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}]")
message(STATUS "  Build type [${CMAKE_BUILD_TYPE}]")
message(STATUS "  Debug postfix [${CMAKE_DEBUG_POSTFIX}]")
if (UNIX)
  message(STATUS "  Code coverage [${ENABLE_COVERAGE}]")
else()
  message(STATUS "  Code coverage [NOT AVAIBLE]")
endif()
if (UNIX)
  message(STATUS "  Google Address Sanitizer [${ENABLE_ASAN}]")
else()
  message(STATUS "  Google Address Sanitizer [NOT AVAIBLE]")
endif()
if (UNIX)
  message(STATUS "  Google Undefined Sanitizer [${ENABLE_USAN}]")
else()
  message(STATUS "  Google Undefined Sanitizer [NOT AVAIBLE]")
endif()
if (UNIX)
  message(STATUS "  Google Thread Sanitizer [${ENABLE_TSAN}]")
else()
  message(STATUS "  Google Thread Sanitizer [NOT AVAIBLE]")
endif()
message(STATUS "  Install prefix [${CMAKE_INSTALL_PREFIX}]")
message(STATUS "  Output path [${EXECUTABLE_OUTPUT_PATH}]")
message(STATUS "  Executable extension [${EXECUTABLE_EXTENSION}]")

message(STATUS "External projects")
find_package(Git REQUIRED QUIET)
if (Git_FOUND)
  message(STATUS "  [X] Git ${GIT_VERSION_STRING}")
else()
  message(STATUS "  [ ] Git")
endif()

find_package(Subversion REQUIRED QUIET)
if (Subversion_FOUND)
  message(STATUS "  [X] Subversion ${Subversion_VERSION_SVN}")
else()
  message(STATUS "  [ ] Subversion")
endif()

if (DOWNLOAD_ASTYLE)
  ExternalProject_Add(astyle GIT_REPOSITORY https://github.com/Bareflank/astyle.git GIT_TAG v1.2 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
  set(ASTYLE_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/astyle${EXECUTABLE_EXTENSION})
  set(ASTYLE_PROJECT astyle)
  message(STATUS "  [X] astyle v1.2")
else()
  set(ASTYLE_EXECUTABLE astyle${EXECUTABLE_EXTENSION})
  message(STATUS "  [ ] astyle v1.2")
endif()

if (DOWNLOAD_CPPCHECK)
  ExternalProject_Add(cppcheck GIT_REPOSITORY https://github.com/danmar/cppcheck.git GIT_TAG 1.81 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
  set(CPPCHECK_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/cppcheck${EXECUTABLE_EXTENSION})
  set(CPPCHECK_PROJECT cppcheck)
  message(STATUS "  [X] cppcheck 1.81")
else()
  set(CPPCHECK_EXECUTABLE cppcheck${EXECUTABLE_EXTENSION})
  message(STATUS "  [ ] cppcheck 1.81")
endif()

find_package(Doxygen QUIET)
if (Doxygen_FOUND)
  message(STATUS "  [X] Doxygen ${DOXYGEN_VERSION}")
else()
  ExternalProject_Add(doxygen GIT_REPOSITORY https://github.com/doxygen/doxygen.git GIT_TAG Release_1_8_13 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
  set(DOXYGEN_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/doxygen${EXECUTABLE_EXTENSION})
  set(DOXYGEN_PROJECT doxygen)
  message(STATUS "  [X] Doxygen 1.8.13")
endif()

message(STATUS "3rd parties")

find_package(call_stack QUIET)
if (CALL_STACK_FOUND)
  message(STATUS "  [X] call_stack")
else()
  add_subdirectory(3rdparty/call_stack)
  message(STATUS "  [X] call_stack master")
endif()

find_package(CURL QUIET)
if (CURL_FOUND)
  message(STATUS "  [X] curl ${CURL_VERSION_STRING}")
else()
  set(OPENSSL_ROOT_DIR /usr/local/Cellar/openssl/1.0.2m)
  add_subdirectory(3rdparty/curl)
  message(STATUS "  [X] curl 7.56.1")
endif()

find_package(easywsclient QUIET)
if (EASYWSCLIENT_FOUND)
  message(STATUS "  [X] easywsclient")
else()
  add_subdirectory(3rdparty/easywsclient)
  message(STATUS "  [X] easywsclient master")
endif()

find_package(GTest QUIET)
if (GTEST_FOUND)
  message(STATUS "  [X] GTest")
else()
  add_subdirectory(3rdparty/googletest)
  set(GTEST_LIBRARIES gtest)
  message(STATUS "  [X] gtest 1.8.0")
endif()

find_package(JPEG QUIET)
if (JPEG_FOUND)
  message(STATUS "  [X] JPEG")
else()
  add_subdirectory(3rdparty/jpeg)
  set(JPEG_LIBRARIES jpeg)
  message(STATUS "  [X] JPEG master")
endif()

find_package(RS232 QUIET)
if (RS232_FOUND)
  message(STATUS "  [X] RS232")
else()
  add_subdirectory(3rdparty/RS-232)
  message(STATUS "  [X] RS232 master")
endif()

find_package(ZLIB QUIET)
if (ZLIB_FOUND)
  message(STATUS "  [X] ZLIB ${ZLIB_VERSION_STRING}")
else()
  add_subdirectory(3rdparty/zlib)
  message(STATUS "  [X] ZLIB master")
endif()

find_package(PNG QUIET)
if (PNG_FOUND)
  message(STATUS "  [X] PNG  ${PNG_VERSION_STRING}")
else()
  add_subdirectory(3rdparty/libpng)
  set(PNG_LIBRARIES libpng)
  message(STATUS "  [X] PNG master")
endif()

message(STATUS "Generating Switch ${Switch_VERSION}")

if (BUILD_SWITCH_CORE)
  message(STATUS "  [X] Switch.Core")
  add_subdirectory("src/Switch.Core")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.Core\"\n")
else()
  message(STATUS "  [ ] Switch.Core")
endif()

if (BUILD_SWITCH_SYSTEM)
  message(STATUS "  [X] Switch.System")
  add_subdirectory("src/Switch.System")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System\"\n")
else()
  message(STATUS "  [ ] Switch.System")
endif()

if (BUILD_SWITCH_SYSTEM_CORE)
  message(STATUS "  [X] Switch.System.Core")
  add_subdirectory("src/Switch.System.Core")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Core\"\n")
else()
  message(STATUS "  [ ] Switch.System.Core")
endif()

if (BUILD_SWITCH_SYSTEM_DRAWING)
  message(STATUS "  [X] Switch.System.Drawing")
  add_subdirectory("src/Switch.System.Drawing")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Drawing\"\n")
else()
  message(STATUS "  [ ] Switch.System.Drawing")
endif()

if (BUILD_SWITCH_SYSTEM_SERVICEMODEL)
  message(STATUS "  [X] Switch.System.ServiceModel")
  add_subdirectory("src/Switch.System.ServiceModel")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.ServiceModel\"\n")
else()
  message(STATUS "  [ ] Switch.System.ServiceModel")
endif()

if (BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
  message(STATUS "  [X] Switch.System.Windows.Forms")
  add_subdirectory("src/Switch.System.Windows.Forms")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.System.Windows.Forms\"\n")
else()
  message(STATUS "  [ ] Switch.System.Windows.Forms")
endif()

if (BUILD_SWITCH_TUNIT_CORE)
  message(STATUS "  [X] Switch.TUnit.Core")
  add_subdirectory("src/Switch.TUnit.Core")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.TUnit.Core\"\n")
else()
  message(STATUS "  [ ] Switch.TUnit.Core")
endif()

if (BUILD_SWITCH_TUNIT_FRAMEWORK)
  message(STATUS "  [X] Switch.TUnit.Framework")
  add_subdirectory("src/Switch.TUnit.Framework")
  file(APPEND src/Switch/include/Switch/Switch.hpp "#include \"Switch/Switch.TUnit.Framework\"\n")
else()
  message(STATUS "  [ ] Switch.TUnit.Framework")
endif()

if (BUILD_SWITCH_TUNIT_MAIN)
  message(STATUS "  [X] Switch.TUnit.Main")
  add_subdirectory("src/Switch.TUnit.Main")
else()
  message(STATUS "  [ ] Switch.TUnit.Main")
endif()

if (BUILD_TESTS)
  message(STATUS "Building Switch Tests")
  enable_testing()

  if (BUILD_SWITCH_CORE)
    message(STATUS "  [X] Switch.Core.ManualTests")
    add_subdirectory("tests/Switch.Core.ManualTests")
    message(STATUS "  [X] Switch.Core.UnitTests")
    add_subdirectory("tests/Switch.Core.UnitTests")
  else()
    message(STATUS "  [ ] Switch.Core.ManualTests")
    message(STATUS "  [ ] Switch.Core.UnitTests")
  endif()

  if (BUILD_SWITCH_SYSTEM)
    message(STATUS "  [X] Switch.System.ManualTests")
    add_subdirectory("tests/Switch.System.ManualTests")
    message(STATUS "  [X] Switch.System.UnitTests")
    add_subdirectory("tests/Switch.System.UnitTests")
  else()
    message(STATUS "  [ ] Switch.System.ManualTests")
    message(STATUS "  [ ] Switch.System.UnitTests")
  endif()

  if (BUILD_SWITCH_SYSTEM_DRAWING)
    message(STATUS "  [X] Switch.System.Drawing.ManualTests")
    add_subdirectory("tests/Switch.System.Drawing.ManualTests")
    message(STATUS "  [X] Switch.System.Drawing.UnitTests")
    add_subdirectory("tests/Switch.System.Drawing.UnitTests")
  else()
    message(STATUS "  [ ] Switch.System.Drawing.ManualTests")
    message(STATUS "  [ ] Switch.System.Drawing.UnitTests")
  endif()

  if (BUILD_SWITCH_SYSTEM_WINDOWS_FORMS)
    message(STATUS "  [X] Switch.System.Windows.Forms.ManualTests")
    add_subdirectory("tests/Switch.System.Windows.Forms.ManualTests")
    message(STATUS "  [X] Switch.System.Windows.Forms.UnitTests")
    add_subdirectory("tests/Switch.System.Windows.Forms.UnitTests")
  else()
    message(STATUS "  [ ] Switch.System.Windows.Forms.ManualTests")
    message(STATUS "  [ ] Switch.System.Windows.Forms.UnitTests")
  endif()

  if (BUILD_SWITCH_TUNIT_CORE)
    message(STATUS "  [X] Switch.TUnit.ManualTests")
    add_subdirectory("tests/Switch.TUnit.ManualTests")
    message(STATUS "  [X] Switch.TUnit.UnitTests")
    add_subdirectory("tests/Switch.TUnit.UnitTests")
  else()
    message(STATUS "  [ ] Switch.TUnit.ManualTests")
    message(STATUS "  [ ] Switch.TUnit.UnitTests")
  endif()

  if (BUILD_SWITCH_TUNIT_FRAMEWORK)
    message(STATUS "  [X] Switch.TUnit.Framework.ManualTests")
    add_subdirectory("tests/Switch.TUnit.Framework.ManualTests")
  else()
    message(STATUS "  [ ] Switch.TUnit.Framework.ManualTests")
  endif()
endif()

add_subdirectory("src/Switch")

install(EXPORT Switch DESTINATION cmake)
install(FILES scripts/cmake/SwitchConfig.cmake scripts/cmake/SwitchDependencies.cmake DESTINATION cmake)

message(STATUS "Custom targets")

# add custom target ${PROJECT_NAME}.Install to install project.
message(STATUS "  [X] ${PROJECT_NAME}.All")
if (WIN32)
  add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
else(UNIX)
  add_custom_target(${PROJECT_NAME}.All "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" -- -j8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
endif()

message(STATUS "  [X] ${PROJECT_NAME}.Check")
add_custom_target(${PROJECT_NAME}.Check COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_ARGS} COMMENT "running cppcheck" DEPENDS ${CPPCHECK_PROJECT})

message(STATUS "  [X] ${PROJECT_NAME}.Format")
add_custom_target(${PROJECT_NAME}.Format COMMAND ${ASTYLE_EXECUTABLE} ${ASTYLE_ARGS} COMMENT "running astyle" DEPENDS ${ASTYLE_PROJECT})

message(STATUS "  [X] ${PROJECT_NAME}.GitCheck")
add_custom_target(${PROJECT_NAME}.GitCheck COMMAND git diff --check HEAD^ COMMENT "running git check")

# add custom target ${PROJECT_NAME}.Install to install project.
message(STATUS "  [X] ${PROJECT_NAME}.Install")
if (WIN32)
  add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install --config ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
else(UNIX)
  add_custom_target(${PROJECT_NAME}.Install "${CMAKE_COMMAND}" --build "${CMAKE_BINARY_DIR}" --target install -- -j8 DEPENDS ${PROJECT_NAME} COMMENT "Installing ${PROJECT_NAME}")
endif()

# add custom target ${PROJECT_NAME}.ReferenceGuide to generate doxygen project reference guide.
message(STATUS "  [X] ${PROJECT_NAME}.ReferenceGuide")
add_custom_target(${PROJECT_NAME}.ReferenceGuide ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxygen.txt WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ReferenceGuide COMMENT "Doxygen Reference Guide generation" DEPENDS ${DOXYGEN_PROJECT} VERBATIM)

# add custom target ${PROJECT_NAME}.Tests to run project tests.
message(STATUS "  [X] ${PROJECT_NAME}.Tests")
add_custom_target(${PROJECT_NAME}.Tests COMMAND ctest --output-on-failure -C ${SWITCH_BUILD_TYPE} DEPENDS ${PROJECT_NAME}.All)
