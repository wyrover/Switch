cmake_minimum_required(VERSION 3.2)

project(3rdparty)

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
#
