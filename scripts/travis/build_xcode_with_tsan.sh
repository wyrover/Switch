#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                       generate, build and install Switch
cd build
#cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_TSAN=ON -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_TSAN=OFF -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . -- -j8
cd ..

# ________________________________________________________________________________________
#                                                                run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
