@echo off
echo Usage
echo   install.bat [/VS:2017 ^| /VS:2015^| /VCPKG vcpkg_install_path] 
echo   [cmake_install_prefix_path] 
echo.
echo   /VS:2017                  : Generate Visual Studio 2017 solution
echo                               (default is no specified param)
echo   /VS:2015                  : Generate Visual Studio 2015 solution
echo   /VCPKG vcpkg_install_path : Specify vcpkg and path where it installed to
echo                               generate the defined Visual Studio solution and
echo                               use thirdparty packages.
echo   cmake_install_prefix_path : Specify the cmake install prefix path. (By
echo                               default the value is set to "C:/usr/local".)
echo. 
echo Example:
echo   install.bat /VS:2015 D:/Projects/libs
echo.
echo Notes
echo   * If you don't specify cmake_install_prefix_path value, the Switch installer
echo     set it to "C:/usr/local" for generate, build and install Switch.
echo   * When install is complete you can find installed Switch files in folder
echo     cmake_install_prefix_path.
echo   * To build your own project using Switch, don't miss to set cmake variable
echo     MAKE_INSTALL_PREFIX to cmake_install_prefix_path value; otherwise cmake 
echo     don't find Switch libraries and include files. See cmake documentation 
echo     (http://cmake.org/documentation) for more information.
echo.
