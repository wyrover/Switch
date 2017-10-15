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

echo Install Switch libraries version %switch_version%, copyright GAMMA Soft, 2017
echo.

set switch_install_devenv="devenv"

if "%1" == "" (
  set switch_install_option=/VS:2017:WIN64
) else if "%1" == "/VCPKG" (
  set switch_install_option=%1
  set switch_nstall_vcpkg_path=%2
  set switch_install_cmake_install_prefix_path=%3
) else if "%1" == "/VS:2017" (
  set switch_install_option=/VS:2017:WIN64
  set switch_install_cmake_install_prefix_path=%2
) else if "%1" == "/VS:2017:WIN32" (
  set switch_install_option=%1
  set switch_install_cmake_install_prefix_path=%2
) else if "%1" == "/VS:2017:WIN64" (
  set switch_install_option=%1
  set switch_install_cmake_install_prefix_path=%2
) else if "%1" == "/VS:2015" (
  set switch_install_option=/VS:2015:WIN64
  set switch_install_cmake_install_prefix_path=%2
) else if "%1" == "/VS:2015:WIN32" (
  set switch_install_option=%1
  set switch_install_cmake_install_prefix_path=%2
) else if "%1" == "/VS:2015:WIN64" (
  set switch_install_option=%1
  set switch_install_cmake_install_prefix_path=%2
) else (
  set switch_install_cmake_install_prefix_path=%1
)

if "%switch_install_cmake_install_prefix_path%" == "" set switch_install_cmake_install_prefix_path=C:/usr/local

if "%switch_install_option%" == "/VCPKG" (
  "%switch_nstall_vcpkg_path%\vcpkg" install curl gtest libjpeg-turbo zlib libpng
  "%switch_nstall_vcpkg_path%\vcpkg" integrate install
  call scripts\install\install_windows_generate_and_build.bat "" "-DCMAKE_TOOLCHAIN_FILE=%switch_nstall_vcpkg_path%/scripts/buildsystems/vcpkg.cmake"
) else if "%switch_install_option%" == "/VS:2017:WIN64" (
  call scripts\install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017 Win64"
) else if "%switch_install_option%" == "/VS:2017:WIN32" (
  call scripts\install\install_windows_generate_and_build.bat -G "Visual Studio 15 2017"
) else if "%switch_install_option%" == "/VS:2015:WIN64" (
  call scripts\install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015 Win64"
) else if "%switch_install_option%" == "/VS:2015:WIN32" (
  call scripts\install\install_windows_generate_and_build.bat -G "Visual Studio 14 2015"
) else (
  call scripts\install\install_windows_usage.bat 
) 

set switch_install_devenv=
set switch_install_option=
set switch_nstall_vcpkg_path=
set switch_install_cmake_install_prefix_path=

