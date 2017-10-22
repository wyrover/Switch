rem echo cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%"
rem timeout /T 2 >nul

IF NOT EXIST "%switch_install_cmake_install_prefix_path%\cmake" (
  mkdir "%switch_install_cmake_install_prefix_path%\cmake"
)

IF NOT EXIST "%switch_install_cmake_install_prefix_path%\include" (
  mkdir "%switch_install_cmake_install_prefix_path%\include"
)

IF NOT EXIST "%switch_install_cmake_install_prefix_path%\lib" (
  mkdir "%switch_install_cmake_install_prefix_path%\lib"
)

if EXIST build (
  del /q /s build
)

mkdir build\3rdparty
cd build\3rdparty
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../3rdparty
devenv "3rdparty.sln" /project install /build Debug
devenv "3rdparty.sln" /project install /build Release

cd..
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ..
devenv "Switch.sln" /project install /build Debug
devenv "Switch.sln" /project install /build Release

mkdir examples
cd examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../examples
start Examples.sln
cd ..\..
