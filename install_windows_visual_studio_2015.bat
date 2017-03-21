@echo off
echo "Install Pcf libraries version 0.2.0, copyright GAMMA Soft, 2017"
echo ""

del /q /s Build
mkdir Build\Examples
mkdir Build\ThirdParties
mkdir c:\usr\local

cd Build\ThirdParties
cmake -G "Visual Studio 14 2015 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ../../ThirdParties
"%VS140COMNTOOLS%\..\IDE\devenv" "ThirdParties.sln" /project install /build Debug
"%VS140COMNTOOLS%\..\IDE\devenv" "ThirdParties.sln" /project install /build Release

cd..
cmake -G "Visual Studio 14 2015 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ..
"%VS140COMNTOOLS%\..\IDE\devenv" "Pcf.sln" /project documentation /build Debug
start Help/html/index.html
"%VS140COMNTOOLS%\..\IDE\devenv" "Pcf.sln" /project install /build Debug
"%VS140COMNTOOLS%\..\IDE\devenv" "Pcf.sln" /project install /build Release

cd Examples
cmake -G "Visual Studio 14 2015 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ../../Examples
rem "%VS140COMNTOOLS%\..\IDE\devenv" "Examples.sln" /project ALL_BUILD /build Release
start Examples.sln
cd ..\..

