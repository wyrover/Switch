#!/usr/bin/env sh

# create build folders
mkdir -p build/3rdparty

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . --target install -- -j8
cd ../..
