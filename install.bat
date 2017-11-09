@echo off
REM Read this first :
REM =================
REM
REM The install.bat file run with all version of Visual Studio 2015 (expect 
REM "Express Edition") and all version of Visual Studio 2017.
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
REM You can now invoke install.bat with vcpkg like this :
REM
REM install.bat /VCPKG C:/Users/YourName/Projects/vcpkg
REM 
REM Remarks
REM -------
REM By default vcpkg install x86 packages. You can set system environment variable VCPKG_DEFAULT_TRIPLET=x64-windows for x64 packages.
REM see https://github.com/Microsoft/vcpkg and https://vcpkg.readthedocs.io/en/latest/ for more informations.

set switch_version=0.4.1
if "%1" == "/?" (
  call scripts\install\install.bat /help
) else (
  call scripts\install\install.bat %*
)
