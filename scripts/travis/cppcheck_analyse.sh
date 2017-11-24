#!/bin/bash

set -ev

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target install -- -j8
cd ../..

# cppcheck analyse
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DDOWNLOAD_CPPCHECK=ON -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
#cmake --build . --target Switch.Check
cd ..
