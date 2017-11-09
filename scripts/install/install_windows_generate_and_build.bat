IF NOT EXIST "%switch_install_cmake_install_prefix_path%\cmake" (mkdir "%switch_install_cmake_install_prefix_path%\cmake")
IF NOT EXIST "%switch_install_cmake_install_prefix_path%\include" (mkdir "%switch_install_cmake_install_prefix_path%\include")
IF NOT EXIST "%switch_install_cmake_install_prefix_path%\lib" (mkdir "%switch_install_cmake_install_prefix_path%\lib")

if EXIST build (del /q /s build)

mkdir build\3rdparty
mkdir build\examples

REM generate, build and install 3rdparty
cd build\3rdparty
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../3rdparty
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..\..

REM generate, build and install Switch
cd build
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ..
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

REM generate examples
cd build\examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../examples
start Examples.sln
cd ..\..
