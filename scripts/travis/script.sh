#!/usr/bin/env sh

# generate, build and install 3rdparty
cd build/3rdparty
cmake -DCMAKE_BUILD_TYPE=Release ../../3rdparty 
cmake --build . -- -j8
sudo cmake --build . --target install -- -j8
cd ../..

# generate, build and install Switch
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON .. 
cmake --build . -- -j8
sudo cmake --build . --target install -- -j8
cd ..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
