@echo off
REM Read this first :
REM =================
REM
REM Before using this install.bat file, be sure you are in "Developer Command Prompt for 
REM VS 2017" or "Developer Command Prompt for VS 2015" command box or be sure your path
REM environment variable contains the folder path containing "devenv.exe" program 
REM (if you do not change the default directory when installing it is 
REM "C:\Program Files\Visual Studio 15\Common7\IDE"; otherwise is your specified path + 
REM "\Common7\IDE" to terminate). In other case the installation will failed.
REM
REM The install.bat file run with all version of Visual Studio 2015 (expect 
REM "Express Edition") and 2017.
REM
REM If you are using Visual Studio 2015 Express Edition upgrade to Visual Studio 2017 
REM Community Edition (download from https://www.visualstudio.com).

echo Install Switch libraries version 0.3.4, copyright GAMMA Soft, 2017
echo.

if "%1" == "" (
  set last_visual_version=true
) else if "%1" == "/VCPKG" (
  set last_visual_version=false
) else if "%1" == "/VS:2017" (
  set last_visual_version=false
) else if "%1" == "/VS:2017:WIN32" (
  set last_visual_version=false
) else if "%1" == "/VS:2017:WIN64" (
  set last_visual_version=false
) else if "%1" == "/VS:2015" (
  set last_visual_version=false
) else if "%1" == "/VS:2015:WIN32" (
  set last_visual_version=false
) else if "%1" == "/VS:2015:WIN64" (
  set last_visual_version=false
) else {
  set last_visual_version=true
)

if "%1" == "/DOC" (
  set generate_doc=true
) else if "%2" == "/DOC" (
  set generate_doc=true
) else if "%2" == "/DOC" (
  set generate_doc=true
) else if "%3" == "/DOC" (
  set generate_doc=true
) else if "%4" == "/DOC" (
  set generate_doc=true
) else (
  set generate_doc=false
)

if "%last_visual_version%" == "true" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017 Win64" %1
) else if "%1" == "/VCPKG" (
  call install\install_windows_vcpkg.bat %2 %3
) else if "%1" == "/VS:2017" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017 Win64" %2
) else if "%1" == "/VS:2017:WIN32" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017" %2
) else if "%1" == "/VS:2017:WIN64" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017 Win64" %2
) else if "%1" == "/VS:2015" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015 Win64" %2
) else if "%1" == "/VS:2015:WIN32" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015" %2
) else if "%1" == "/VS:2015:WIN64" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015 Win64" %2
) else  if "%1" == "/?" (
  call install\install_windows_usage.bat 
) else  if "%1" == "/help" (
  call install\install_windows_usage.bat 
) else (
  call install\install_windows_usage.bat 
) 
