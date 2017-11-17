echo SWITCH_BUILD_WIN32 = %SWITCH_BUILD_WIN32%
echo SWITCH_BUILD_WIN64 = %SWITCH_BUILD_WIN64%

rem Switch build 32 bits
if "%SWITCH_BUILD_WIN32%" == "true" (
  rem create build folders
  mkdir build32\3rdparty

  rem generate, build and install 3rdparty
  cd build32\3rdparty
  cmake ../../3rdparty -DCMAKE_INSTALL_PREFIX=/usr/local/32
  cmake --build . --target install --config Release
  cd ..\..

  rem generate, build and install Switch
  cd build32
  cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/32 -DBUILD_TESTS=ON
  cmake --build . --config Release
  cd ..
)

rem Switch build 64 bits
if "%SWITCH_BUILD_WIN64%" == "true" (
  rem create build folders
  mkdir build64\3rdparty

  rem generate, build and install 3rdparty
  cd build64\3rdparty
  cmake -G "Visual Studio 15 2017 Win64" ../../3rdparty -DCMAKE_INSTALL_PREFIX=/usr/local/64
  cmake --build . --target install --config Release
  cd ..\..

  rem generate, build and install Switch
  cd build54
  cmake -G "Visual Studio 15 2017 Win64" .. -DCMAKE_INSTALL_PREFIX=/usr/local/64 -DBUILD_TESTS=ON
  cmake --build . --config Release
  cd ..
)
