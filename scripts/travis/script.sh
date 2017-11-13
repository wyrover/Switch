#!/usr/bin/env sh

# create build folders
mkdir -p build/3rdparty

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release 
cmake --build . -- -j8
sudo cmake --build . --target install
cd ../..

# generate, build and install Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON 
cmake --build . -- -j8
cd ..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
