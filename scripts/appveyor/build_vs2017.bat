rem ______________________________________________________________________________________
rem                                                                   Switch build 32 bits
if DEFINED SWITCH_BUILD_WIN32 (
  rem create build folder
  mkdir build32

  rem generate, build Switch
  cd build32
  cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/32 -DBUILD_TESTS=ON
  cmake --build . --config Release
  cd ..
)

rem __________________________________________________________________ ____________________
rem                                                                   Switch build 64 bits
if DEFINED SWITCH_BUILD_WIN64 (
  rem create build folder
  mkdir build64

  rem generate, build and install Switch
  cd build64
  cmake -G "Visual Studio 15 2017 Win64" .. -DCMAKE_INSTALL_PREFIX=/usr/local/64 -DBUILD_TESTS=ON
  cmake --build . --config Release
  cd ..
)
