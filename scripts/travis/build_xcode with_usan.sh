#!/bin/bash

set -ev

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . --target install -- -j8
cd ../..

# generate, build and install Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_USAN=ON -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . -- -j8
cd ..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
