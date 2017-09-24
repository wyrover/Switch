set cmake_install_prefix_path=C:/usr/local
if not "%3" == "" set cmake_install_prefix_path=%3

rem echo cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../ThirdParties
rem goto end

del /q /s bin
mkdir bin\Examples
mkdir bin\ThirdParties
mkdir "%cmake_install_prefix_path%"

cd bin\ThirdParties
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../ThirdParties
"devenv" "ThirdParties.sln" /project install /build Debug
rem "devenv" "ThirdParties.sln" /project install /build Release

cd..
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ..
rem "devenv" "Switch.sln" /project documentation /build Debug
rem start Help/html/index.html
"devenv" "Switch.sln" /project install /build Debug
rem "devenv" "Switch.sln" /project install /build Release

cd Examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../Examples
start Examples.sln
cd ..\..

rem :end
