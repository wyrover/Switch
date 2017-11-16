#!/usr/bin/env sh

# generate, build and install Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_COVERAGE=ON
cmake --build . -- -j8
cd ..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
