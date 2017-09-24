@echo off
echo Install Switch libraries version 0.3.4, copyright GAMMA Soft, 2017
echo.

if "%1" == "" set last_visual_version=true
if not "%1" == "/VCPKG" set last_visual_version=true
if not "%1" == "/VS:2017" set last_visual_version=true
if not "%1" == "/VS:2015" set last_visual_version=true

if "last_visual_version" == "true" (
  call install\install_windows_generate_and_build.bat "-G Visual Studio 15 2017 Win64" %1
) else if "%1" == "/VCPKG" (
  call install\install_windows_vcpkg.bat %2 %3
) else if "%1" == "/VS:2017" (
  call install\install_windows_generate_and_build.bat "-G Visual Studio 15 2017 Win64" %2
) else if "%1" == "/VS:2015" (
  call install\install_windows_generate_and_build.bat "-G Visual Studio 14 2015 Win64" %2
) else  if "%1" == "/?" (
  call install\install_windows_usage.bat 
) else  if "%1" == "/help" (
  call install\install_windows_usage.bat 
) else (
  call install\install_windows_usage.bat 
) 
