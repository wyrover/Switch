rem create build folders
mkdir build\3rdparty
mkdir build\examples

rem generate, build and install 3rdparty
cd build\3rdparty
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../3rdparty
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..\..

rem generate, build and install Switch
cd build
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ..
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

rem generate examples
cd build\examples
cmake %1 %2 -DCMAKE_INSTALL_PREFIX:STRING="%switch_install_cmake_install_prefix_path%" ../../examples
cd ..\..

# launch examples
start build\examples\Examples.sln
