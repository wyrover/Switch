#!/usr/bin/env bash

# generate, build and install Switch
cd build
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON .. 
  cmake --build . --target install -- -j8
elif [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  cmake -G "Xcode" -DBUILD_TESTS=ON .. 
  cmake --build . --target install --Config Release
fi
cd ..

# generate examples
cd build/examples
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  cmake -DCMAKE_BUILD_TYPE=Release ../../examples 
  cmake --build . --target install -- -j8
elif [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  cmake -G "Xcode" ../../examples 
  cmake --build . --target install --Config Release
fi
cd ../..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
