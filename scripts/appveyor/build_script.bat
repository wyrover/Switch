mkdir build\3rdparty
cd build\3rdparty
cmake ../../3rdparty -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build . --target install --config Release
cd ..
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local -DBUILD_TESTS=ON
cmake --build . --config Release
cd ..
