cmake_minimum_required(VERSION 3.5)

project(ThirdParties)

#________________________________________________________________________________
#                                                                      call_stack
find_package(call_stack QUIET)
message(STATUS "Found call_stack : " ${call_stack_FOUND})
if (NOT call_stack_FOUND)
  message(STATUS "Add ThirdParty call_stack")
  add_subdirectory(call_stack)
  set_target_properties(call_stack PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                            curl
find_package(CURL QUIET)
message(STATUS "Found CURL : " ${CURL_FOUND})
if (NOT CURL_FOUND)
  message(STATUS "Add ThirdParty curl")
  option(BUILD_TESTING "Build the testing tree" OFF)
  option(ENABLE_MANUAL "to provie the built-in manual" OFF)
  add_subdirectory(curl)
  set_target_properties(libcurl PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                    easywsclient
find_package(easywsclient QUIET)
message(STATUS "Found easywsclient : " ${easywsclient_FOUND})
if (NOT easywsclient_FOUND)
  message(STATUS "Add ThirdParty easywsclient")
  add_subdirectory(easywsclient)
  set_target_properties(easywsclient PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                           Rs232
find_package(Rs232 QUIET)
message(STATUS "Found Rs232 : " ${Rs232_FOUND})
if (NOT Rs232_FOUND)
  message(STATUS "Add ThirdParty Rs232")
  add_subdirectory(Rs232)
  set_target_properties(Rs232 PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                            zlib
find_package(ZLIB QUIET)
  message(STATUS "Found ZLIB : " ${ZLIB_FOUND})
if (NOT ZLIB_FOUND)
  message(STATUS "Add ThirdParty zlib")
  add_subdirectory(zlib)
  set(ZLIB_LIBRARIES zlib)
  set(ZLIB_LIBRARY zlib)
  set_target_properties(zlib PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                            jpeg
find_package(JPEG QUIET)
message(STATUS "Found JPEG : " ${JPEG_FOUND})
if (NOT JPEG_FOUND)
  message(STATUS "Add ThirdParty jpeg")
  add_subdirectory(jpeg)
  set(JPEG_LIBRARIES jpeg)
  set_target_properties(jpeg PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                          libpng
find_package(PNG QUIET)
message(STATUS "Found libpng : " ${PNG_FOUND})
if (NOT PNG_FOUND)
  message(STATUS "Add ThirdParty libpng")
  add_subdirectory(libpng)
  set_target_properties(libpng PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#                                                                      googletest
find_package(GTest QUIET)
message(STATUS "Found GTest : " ${GTEST_FOUND})
if (NOT GTEST_FOUND)
  message(STATUS "Add ThirdParty googletest")
  option(BUILD_GMOCK "Build the google mock subproject" OFF)
  option(BUILD_GTEST "Build the google test subproject" ON)
  option(gtest_force_shared_crt "Use shared (DLL) run-time lib even when Google Test is built as static lib." ON)
  add_subdirectory(googletest)
  set_target_properties(gtest PROPERTIES FOLDER ThirdParty)
  set_target_properties(gtest_main PROPERTIES FOLDER ThirdParty)
endif()

#________________________________________________________________________________
#
