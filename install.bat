@echo off
if "%1" == "2017" (
  call install\install_windows_visual_studio_2017.bat 
) else if "%1" == "2015" (
  call install\install_windows_visual_studio_2015.bat 
) else echo "param can only be 2017 or 2015" 
