@echo off
echo Install Pcf libraries version 0.3.0, copyright GAMMA Soft, 2017
echo.

@echo off
if "%1" == "" (
  call install\install_windows_visual_studio_2017.bat 
) else if "%1" == "VS2017" (
  call install\install_windows_visual_studio_2017.bat 
) else if "%1" == "VS2015" (
  call install\install_windows_visual_studio_2015.bat 
) else (
  echo   usage Install [VS2017 ^| VS2015]
  echo       VS2017 : Visual Studio 2017 (default)
  echo       VS2015 : Visual Studio 2015
) 
