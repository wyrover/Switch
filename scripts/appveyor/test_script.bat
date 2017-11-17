rem run registered unit tests 32 bits
if %SWITCH_BUILD_WIN32% == true (
  cd build32
  ctest --output-on-failure --build-config Release
  cd ..
)

rem run registered unit tests 64 bits
if %SWITCH_BUILD_WIN64% == true (
  cd build64
  ctest --output-on-failure --build-config Release
  cd ..
)
