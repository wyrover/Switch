set cmake_install_prefix_path=C:/usr/local
if not "%3" == "" set cmake_install_prefix_path=%3

echo cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%"
timeout /T 2 >nul

set devenv="devenv"

del /q /s bin 2>nul
mkdir bin\Examples 2>nul
mkdir bin\3rdparty 2>nul
mkdir "%cmake_install_prefix_path%" 2>nul

cd bin\3rdparty
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../3rdparty
%devenv% "ThirdParties.sln" /project install /build Debug
%devenv% "ThirdParties.sln" /project install /build Release

cd..
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ..
if "%genearte_doc%" == "true" (
  %devenv% "Switch.sln" /project documentation /build Debug
  start Help/html/index.html
)

%devenv% "Switch.sln" /project install /build Debug
%devenv% "Switch.sln" /project install /build Release

cd Examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../Examples
start Examples.sln
cd ..\..