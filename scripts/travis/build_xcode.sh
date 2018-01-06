#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                       generate, build and install Switch
cd build
# ENABLE_COVERAGE deactivated if not the job exceeds the maximum time limit.
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_COVERAGE=OFF -DCMAKE_INSTALL_PREFIX=~/usr/local
cmake --build . -- -j8
cd ..

# ________________________________________________________________________________________
#                                                                run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
