@echo off
echo   usage Install [/VS:2017 ^| /VS:2015]
echo       /VS:2017 : Visual Studio 2017 (default)
echo       /VS:2015 : Visual Studio 2015
echo.
echo Notes
echo   * By default the cmake variable CMAKE_INSTALL_PREFIX is set to 
echo     "C:/usr/local".
echo   * When install is complete you can find installed Pcf files in folder
echo     "C:/usr/local".
echo   * To build your own project using Pcf, don't miss to set cmake variable
echo     MAKE_INSTALL_PREFIX to "C:/usr/local"; otherwise cmake don't find Pcf
echo     libraries and include files. See cmake documentation 
echo     (http://cmake.org/documentation) for more information.
echo.
