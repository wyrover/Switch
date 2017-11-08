#!/usr/bin/env bash
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  sudo apt-get update
  sudo apt-get install clang libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y
fi

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  brew update
  brew install curl doxygen gtkmm3 jpeg libpng zlib -y
fi
