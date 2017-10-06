rem echo Install Switch = cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%"
rem echo Install doc = %switch_install_generate_doc%
rem echo devenv = %switch_install_devenv%
rem timeout /T 2 >nul

del /q /s bin 2>nul
mkdir bin\Examples 2>nul
mkdir bin\3rdparty 2>nul
mkdir "%switch_install_cmake_install_prefix_path%" 2>nul

cd bin\3rdparty
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../3rdparty
%switch_install_devenv% "3rdparty.sln" /project install /build Debug
%switch_install_devenv% "3rdparty.sln" /project install /build Release

cd..
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ..
if "%switch_install_generate_doc%" == "true" (
  %switch_install_devenv% "Switch.sln" /project documentation /build Debug
  start Help/html/index.html
)

%switch_install_devenv% "Switch.sln" /project install /build Debug
%switch_install_devenv% "Switch.sln" /project install /build Release

cd Examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../Examples
start Examples.sln
cd ..\..
