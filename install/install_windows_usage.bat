@echo off
echo Usage
echo   install.bat [/VS:2017[:WIN32 ^| :WIN64] ^| /VS:2015[:WIN32 ^| :WIN64] ^|
echo   /VCPKG vcpkg_install_path] [cmake_install_prefix_path]  [/DOC]
echo.
echo   /VS:2017                  : Install 64 bits version for Visual Studio 2017.
echo                               (default is no specified param)
echo   /VS:2017:WIN64            : Install 64 bits version for Visual Studio 2017.
echo   /VS:2017:WIN32            : Install 32 bits version for Visual Studio 2017.
echo   /VS:2015                  : Install 64 bits version for Visual Studio 2015.
echo   /VS:2015:WIN64            : Install 64 bits version for Visual Studio 2015.
echo   /VS:2015:WIN32            : Install 32 bits version for Visual Studio 2015.
echo   /VCPKG vcpkg_install_path : Specify vcpkg and path where it installed to
echo                               install for defined Visual Studio solution and
echo                               use thirdparty packages.
echo   cmake_install_prefix_path : Specify the cmake install prefix path. (By
echo                               default the value is set to "C:/usr/local".)
echo   /DOC                      : Install Doxygen documentations in 
echo                               ".\bin\help\html".
echo. 
echo Example:
echo   install.bat /VS:2015:WIN32 D:/Projects/libs
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
