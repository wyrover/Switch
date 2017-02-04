@echo off
del /q /s Build
mkdir Build\Examples
mkdir Build\ThirdParties
mkdir usr/local

cd Build\ThirdParties
cmake -G "Visual Studio 14 2015 Win64" -D CMAKE_INSTALL_PREFIX:STRING:"C=/usr/local" ../../ThirdParties
"%VS140COMNTOOLS%\..\IDE\devenv" "ThirdParties.sln" /project install /build Debug
cd ..\..