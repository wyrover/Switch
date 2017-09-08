@echo off
echo Install Switch libraries version 0.3.3, copyright GAMMA Soft, 2017
echo.

if "%1" == "" (
  call install\install_windows_visual_studio_2017.bat 
) else if "%1" == "/VS:2017" (
  call install\install_windows_visual_studio_2017.bat 
) else if "%1" == "/VS:2015" (
  call install\install_windows_visual_studio_2015.bat 
) else  if "%1" == "/?" (
  call install\install_windows_usage.bat 
) else  if "%1" == "/help" (
  call install\install_windows_usage.bat 
) else (
  call install\install_windows_usage.bat 
) 
