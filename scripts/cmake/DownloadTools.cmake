macro(DownloadTools)
  print("Tools:")

  #_______________________________________________________________________________________
  #                                                                                    Git
  find_package(Git REQUIRED QUIET)
  if (Git_FOUND)
    print("  [X] Git ${GIT_VERSION_STRING}")
  else()
    print("  [ ] Git")
  endif()

  #_______________________________________________________________________________________
  #                                                                                 astyle
  if (DOWNLOAD_ASTYLE)
    print("  [X] astyle 3.0.1 (*)")
    ExternalProject_Add(astyle GIT_REPOSITORY https://github.com/Bareflank/astyle.git GIT_TAG v1.2 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
    set(ASTYLE_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/astyle)
    set(ASTYLE_PROJECT astyle)
  else()
    set(ASTYLE_EXECUTABLE astyle)
    print("  [ ] astyle")
  endif()

  #_______________________________________________________________________________________
  #                                                                               cppcheck
  if (DOWNLOAD_CPPCHECK)
    print("  [X] cppcheck 1.81 (*)")
    ExternalProject_Add(cppcheck GIT_REPOSITORY https://github.com/danmar/cppcheck.git GIT_TAG 1.81 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
    set(CPPCHECK_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/cppcheck)
    set(CPPCHECK_PROJECT cppcheck)
  else()
    set(CPPCHECK_EXECUTABLE cppcheck)
    print("  [ ] cppcheck")
  endif()

  #_______________________________________________________________________________________
  #                                                                                Doxygen
  find_package(Doxygen QUIET)
  if (Doxygen_FOUND)
    print("  [X] Doxygen ${DOXYGEN_VERSION}")
  elseif(DOWNLOAD_DOXYGEN)
    print("  [X] Doxygen 1.8.13 (*)")
    ExternalProject_Add(doxygen GIT_REPOSITORY https://github.com/doxygen/doxygen.git GIT_TAG Release_1_8_13 GIT_SHALLOW 1 CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR})
    set(Doxygen_FOUND TRUE)
    set(DOXYGEN_EXECUTABLE ${CMAKE_BINARY_DIR}/bin/doxygen)
    set(DOXYGEN_PROJECT doxygen)
  else()
    set(DOXYGEN_EXECUTABLE doxygen)
    print("  [ ] Doxygen")
  endif()
endmacro()
