#!/usr/bin/env bash

if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  export CC=clang
  export CXX=clang++
fi

if [ ! -d "/usr/local/bin" ]; then sudo mkdir -p /usr/local/bin; fi
if [ ! -d "/usr/local/cmake" ]; then sudo mkdir -p /usr/local/cmake; fi
if [ ! -d "/usr/local/include" ]; then sudo mkdir -p /usr/local/include; fi
if [ ! -d "/usr/local/lib" ]; then sudo mkdir -p /usr/local/lib; fi

sudo chown -R $(whoami) /usr/local/bin
sudo chown -R $(whoami) /usr/local/cmake
sudo chown -R $(whoami) /usr/local/include
sudo chown -R $(whoami) /usr/local/lib

if [ -d ./build ]; then rm -r -f build; fi

mkdir -p build/3rdparty
mkdir -p build/examples
