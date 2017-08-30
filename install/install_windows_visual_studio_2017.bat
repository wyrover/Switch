del /q /s bin
mkdir bin\Examples
mkdir bin\ThirdParties
mkdir c:\usr\local

cd bin\ThirdParties
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ../../ThirdParties
"devenv" "ThirdParties.sln" /project install /build Debug
"devenv" "ThirdParties.sln" /project install /build Release

cd..
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ..
"devenv" "Switch.sln" /project documentation /build Debug
start Help/html/index.html
"devenv" "Switch.sln" /project install /build Debug
"devenv" "Switch.sln" /project install /build Release

cd Examples
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ../../Examples
rem "devenv" "Examples.sln" /project ALL_BUILD /build Release
start Examples.sln
cd ..\..

