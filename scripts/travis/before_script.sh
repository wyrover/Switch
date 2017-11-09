#!/usr/bin/env bash

# set clang as drfault cmake compiler
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  export CC=clang-3.9
  export CXX=clang-3.9++
fi

# create missing install folders
if [ ! -d "/usr/local/bin" ]; then sudo mkdir -p /usr/local/bin; fi
if [ ! -d "/usr/local/cmake" ]; then sudo mkdir -p /usr/local/cmake; fi
if [ ! -d "/usr/local/include" ]; then sudo mkdir -p /usr/local/include; fi
if [ ! -d "/usr/local/lib" ]; then sudo mkdir -p /usr/local/lib; fi

# change folders oxwer
sudo chown -R $(whoami) /usr/local/bin
sudo chown -R $(whoami) /usr/local/cmake
sudo chown -R $(whoami) /usr/local/include
sudo chown -R $(whoami) /usr/local/lib

# remove old build files
if [ -d ./build ]; then rm -r -f build; fi

# create new build folders
mkdir -p build/3rdparty
mkdir -p build/examples
