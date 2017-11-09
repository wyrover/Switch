#!/usr/bin/env bash

# update packages manager
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  sudo apt-get update
elif [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  brew update
fi
