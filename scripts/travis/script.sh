#!/usr/bin/env sh

# install curl on macOS
if [[ "${TRAVIS_OS_NAME}" == "osx" ]]; then
  brew update
  brew install curl
fi

# create build folders
mkdir -p build/3rdparty

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release 
cmake --build . -- -j8
sudo cmake --build . --target install
cd ../..

# generate, build and install Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_TESTS=ON -DENABLE_COVERAGE=ON
cmake --build . -- -j8
cd ..

# run registered unit tests
cd build
ctest --output-on-failure --build-config Release
cd ..
export CODECOV_TOKEN="6f14306e-b89d-4ee1-a370-4549f15a14b6"
bash <(curl -s https://codecov.io/bash)
