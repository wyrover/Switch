echo Install Switch libraries version %switch_version%, copyright GAMMA Soft, 2017
echo.

if "%1" == "" (
  set switch_install_option=/VS:2017:WIN64
) else if "%1" == "/VCPKG" (
  set switch_install_option=%1
  set switch_install_vcpkg_path=%2
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

set devenv=devenv
devenv /? >nul
if %ERRORLEVEL%==9009 (
  set devenv=
)

if "%1" == "/help" (
  call scripts\install\install_windows_usage.bat 
) else if "%devenv%" == "" (
  echo.
  echo Installation failed : Visual Studio not found!
  echo.
  echo Before using this install.bat file, be sure you are in "Developer Command Prompt for 
  echo VS 2017" or "Developer Command Prompt for VS 2015" command box or be sure your path
  echo environment variable contains the folder path containing "devenv.exe" program 
  echo ^(if you do not change the default directory when installing it is 
  echo "C:\Program Files\Visual Studio 15\Common7\IDE"; otherwise is your specified path + 
  echo "\Common7\IDE" to terminate^).
  echo.
) else if "%switch_install_option%" == "/VCPKG" (
  "%switch_install_vcpkg_path%\vcpkg" install curl gtest libjpeg-turbo zlib libpng
  "%switch_install_vcpkg_path%\vcpkg" integrate install
  call scripts\install\install_windows_generate_and_build.bat "" "-DCMAKE_TOOLCHAIN_FILE=%switch_install_vcpkg_path%/scripts/buildsystems/vcpkg.cmake"
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

set devenv=
set switch_install_option=
set switch_install_vcpkg_path=
set switch_install_cmake_install_prefix_path=

