rem create build folders
mkdir build\3rdparty

rem generate, build and install 3rdparty
cd build\3rdparty
cmake ../../3rdparty -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build . --target install --config Release
cd ../..

rem generate, build and install Switch
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_TESTS=ON
cmake --build . --config Release
cd ..
