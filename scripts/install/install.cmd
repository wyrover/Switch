@echo off
echo Install Switch libraries version %switch_version%, copyright Gammasoft, 2018
echo.

rem ______________________________________________________________________________________
rem                                                     generate, build and install Switch
mkdir build\examples
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=c:/usr/local %*
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

rem ______________________________________________________________________________________
rem                                                           generate and launch examples
cd build\examples
cmake ../../examples -DCMAKE_INSTALL_PREFIX=c:/usr/local %*
start Examples.sln
cd ..\..
