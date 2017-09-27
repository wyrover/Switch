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
REM
REM
REM VCPKG
REM =====
REM
REM If you want use vcpkg and if it not installed on your system, open a cmd box type next lines to install it :
REM
REM mkdir C:/Users/YourName/Projects/vcpkg
REM cd C:/Users/YourName/Projects/vcpkg
REM git clone https://github.com/Microsoft/vcpkg .
REM .\bootstrap-vcpkg.bat
REM .\vcpkg integrate install
REM
REM you can invoke install with vcpkg like this :
REM install.bat /VCPKG C:/Users/YourName/Projects/vcpkg
REM 
REM Remarks
REM -------
REM by default vcpkg install x86 packages. You can set system environment variable VCPKG_DEFAULT_TRIPLET=x64-windows for x64 packages.
REM see https://github.com/Microsoft/vcpkg and https://vcpkg.readthedocs.io/en/latest/ for more informations.

echo Install Switch libraries version 0.3.4, copyright GAMMA Soft, 2017
echo.

if "%1" == "" (
  set option=/VS:2017:WIN64
) else if "%1" == "/VCPKG" (
  set option=%1
) else if "%1" == "/VS:2017" (
  set option=/VS:2017:WIN64
) else if "%1" == "/VS:2017:WIN32" (
  set option=%1
) else if "%1" == "/VS:2017:WIN64" (
  set option=%1
) else if "%1" == "/VS:2015" (
  set option=/VS:2015:WIN64
) else if "%1" == "/VS:2015:WIN32" (
  set option=%1
) else if "%1" == "/VS:2015:WIN64" (
  set option=%1
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

if "%option%" == "/VCPKG" (
  call install\install_windows_vcpkg.bat %2 %3
) else if "%option%" == "/VS:2017:WIN64" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017 Win64" %2
) else if "%option%" == "/VS:2017:WIN32" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017" %2
) else if "%option%" == "/VS:2015:WIN64" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015 Win64" %2
) else if "%option%" == "/VS:2015:WIN32" (
  call install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015" %2
) else (
  call install\install_windows_usage.bat 
) 
