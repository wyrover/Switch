#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                       generate, build and install Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_COVERAGE=ON -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
#cmake --build . --config Release -- -j8
cd ..

# ________________________________________________________________________________________
#                                                                run registered unit tests
cd build
#ctest --output-on-failure --build-config Release
cd ..
