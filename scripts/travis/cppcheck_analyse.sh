#!/bin/bash

set -ev

# cppcheck analyse
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DDOWNLOAD_CPPCHECK=ON -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
#cmake --build . --target Switch.Check
cd ..
