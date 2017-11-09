#!/usr/bin/env bash

# generate, build and install 3rdparty
cd build/3rdparty
cmake -DCMAKE_BUILD_TYPE=Release ../../3rdparty 
cmake --build . --target install
cd ../..

# generate, build and install Switch
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON ..
cmake --build . --target install
cd ..

# generate examples
cd build/examples
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON ../../examples
cd ../..

# run unittests
cd build
ctest --output-on-failure --build-config Release
cd..
