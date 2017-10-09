rem echo cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%"
rem timeout /T 2 >nul

mkdir "%switch_install_cmake_install_prefix_path%" 2>nul

del /q /s build 2>nul
mkdir build\3rdparty 2>nul
cd build\3rdparty
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../3rdparty
%switch_install_devenv% "3rdparty.sln" /project install /build Debug
%switch_install_devenv% "3rdparty.sln" /project install /build Release

cd..
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ..
%switch_install_devenv% "Switch.sln" /project install /build Debug
%switch_install_devenv% "Switch.sln" /project install /build Release

mkdir examples 2>nul
cd examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../examples
start Examples.sln
cd ..\..
