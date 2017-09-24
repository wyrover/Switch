set cmake_install_prefix_path=C:/usr/local
if not "%2" == "" set cmake_install_prefix_path=%2

del /q /s bin
mkdir bin\Examples
mkdir bin\ThirdParties
mkdir c:\usr\local

cd bin\ThirdParties
cmake "%1" -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../ThirdParties
"devenv" "ThirdParties.sln" /project install /build Debug
"devenv" "ThirdParties.sln" /project install /build Release

cd..
cmake "%1" -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ..
"devenv" "Switch.sln" /project documentation /build Debug
start Help/html/index.html
"devenv" "Switch.sln" /project install /build Debug
"devenv" "Switch.sln" /project install /build Release

cd Examples
cmake "%1" -DCMAKE_INSTALL_PREFIX:STRING="%cmake_install_prefix_path%" ../../Examples
rem "devenv" "Examples.sln" /project ALL_BUILD /build Release
start Examples.sln
cd ..\..

