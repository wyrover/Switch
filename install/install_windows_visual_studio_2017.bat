del /q /s Build
mkdir Build\Examples
mkdir Build\ThirdParties
mkdir c:\usr\local

cd Build\ThirdParties
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ../../ThirdParties
"devenv" "ThirdParties.sln" /project install /build Debug
"devenv" "ThirdParties.sln" /project install /build Release

cd..
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ..
"devenv" "Pcf.sln" /project documentation /build Debug
start Help/html/index.html
"devenv" "Pcf.sln" /project install /build Debug
"devenv" "Pcf.sln" /project install /build Release

cd Examples
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ../../Examples
rem "devenv" "Examples.sln" /project ALL_BUILD /build Release
start Examples.sln
cd ..\..

