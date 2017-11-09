#!/usr/bin/env bash

# install needed packages and libraries
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  sudo apt-get install clang-3.9 lldb-3.9 libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y
elif [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  brew install curl jpeg libpng zlib -y
fi
