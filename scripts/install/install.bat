@echo off
echo Install Switch libraries version %switch_version%, copyright GAMMA Soft, 2017
echo.

rem create build folders
mkdir build\examples

rem generate, build and install Switch
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

rem generate and launch examples
cd build\examples
cmake ../../examples -DCMAKE_INSTALL_PREFIX:STRING=/usr/local %*
start Examples.sln
cd ..\..
