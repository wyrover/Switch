@echo off
echo Install Switch libraries version %switch_version%, copyright GAMMA Soft, 2017
echo.

rem create build folders
mkdir build\3rdparty
mkdir build\examples

rem generate, build and install 3rdparty
cd build\3rdparty
cmake ../../3rdparty -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..\..

rem generate, build and install Switch
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

rem generate examples
cd build\examples
cmake -DCMAKE_INSTALL_PREFIX:STRING=/usr/local ../../examples
start Examples.sln
cd ..\..
