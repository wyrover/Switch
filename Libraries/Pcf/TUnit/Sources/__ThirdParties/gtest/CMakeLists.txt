cmake_minimum_required(VERSION 3.0.2)

project(gtest VERSION 1.7.2)

#Create the list of source files
set(SOURCE_FILES
./src/gtest-death-test.cc
./src/gtest-filepath.cc
./src/gtest-internal-inl.h
./src/gtest-port.cc
./src/gtest-printers.cc
./src/gtest-test-part.cc
./src/gtest-typed-test.cc
./src/gtest.cc
)

#Create the list of include files
set(INCLUDE_FILES
./include/gtest/gtest
./include/gtest/gtest-death-test.h
./include/gtest/gtest-message.h
./include/gtest/gtest-param-test.h
./include/gtest/gtest-printers.h
./include/gtest/gtest-spi.h
./include/gtest/gtest-test-part.h
./include/gtest/gtest-typed-test.h
./include/gtest/gtest.h
./include/gtest/gtest_pred_impl.h
./include/gtest/gtest_prod.h
./include/gtest/internal/gtest-death-test-internal.h
./include/gtest/internal/gtest-filepath.h
./include/gtest/internal/gtest-internal.h
./include/gtest/internal/gtest-linked_ptr.h
./include/gtest/internal/gtest-param-util-generated.h
./include/gtest/internal/gtest-param-util.h
./include/gtest/internal/gtest-port.h
./include/gtest/internal/gtest-string.h
./include/gtest/internal/gtest-tuple.h
./include/gtest/internal/gtest-type-util.h
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#Add include files under includes group (Optional)
source_group(include REGULAR_EXPRESSION "/include/[-_,A-Za-z0-9]+\\.(c*|h*)")
source_group(include\\${PROJECT_NAME} REGULAR_EXPRESSION "/include/${PROJECT_NAME}/[-_,A-Za-z0-9]+\\.(c*|h*)")
source_group(include\\${PROJECT_NAME}\\internal REGULAR_EXPRESSION "/include/${PROJECT_NAME}/internal/[-_,A-Za-z0-9]+\\.(c*|h*)")

#Add source files under the Sources group
source_group(src REGULAR_EXPRESSION "/src/[-_,A-Za-z0-9]+\\.(c*|h*)")

if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /wd4100 /wd4312 /wd4355 /wd4456 /wd4458")
  set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Od /Zi /RTC1 /D_DEBUG /DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /Gy /O2 /Oi /GL- /DNDEBUG /DRELEASE")
endif ()

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()
 
add_library(gtest STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(gtest PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
set_target_properties(gtest PROPERTIES FOLDER Pcf/TUnit/__ThirdParties)


set(CMAKE_INSTALL_PREFIX "${HOME}/Libraries/${PROJECT_NAME}/${PROJECT_VERSION}${INSTALL_REV}")
#install(EXPORT ${PROJECT_NAME} DESTINATION cmake/)
#install(FILES ${PROJECT_NAME}Config.cmake DESTINATION cmake) 
install(TARGETS gtest EXPORT Pcf DESTINATION lib) 
install(DIRECTORY "./include/."  DESTINATION include PATTERN ".svn" EXCLUDE)

if(MSVC)
  target_compile_options(gtest PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:gtest>/gtest${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(gtest PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:gtest>/gtest.pdb>")
  install(FILES "$<TARGET_FILE_DIR:gtest>/gtest${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:gtest>/gtest.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
