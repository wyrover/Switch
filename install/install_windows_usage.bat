@echo off
echo   usage Install [/VS:2017 ^| /VS:2015]
echo       /VS:2017 : Visual Studio 2017 (default is no specified param)
echo       /VS:2015 : Visual Studio 2015
echo.
echo Notes
echo   * The Pcf installer set cmake variable CMAKE_INSTALL_PREFIX to 
echo     "C:/usr/local" for generate, build and install Pcf.
echo   * When install is complete you can find installed Pcf files in folder
echo     "C:/usr/local".
echo   * To build your own project using Pcf, don't miss to set cmake variable
echo     MAKE_INSTALL_PREFIX to "C:/usr/local"; otherwise cmake don't find Pcf
echo     libraries and include files. See cmake documentation 
echo     (http://cmake.org/documentation) for more information.
echo.
