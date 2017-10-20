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

if "%switch_install_option%" == "/VCPKG" (
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

set switch_install_option=
set switch_install_vcpkg_path=
set switch_install_cmake_install_prefix_path=

