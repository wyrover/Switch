mkdir build\3rdparty
cd build\3rdparty
cmake -G "Visual Studio 15 2017 Win64" ../../3rdparty -DCMAKE_INSTALL_PREFIX:STRING=C:/usr/local
cmake --build . --target install --config Release
cd ..
cmake -G "Visual Studio 15 2017 Win64" .. -DBUILD_TESTS=ON -DCMAKE_INSTALL_PREFIX:STRING=C:/usr/local
cmake --build . --config Release
cd ..
