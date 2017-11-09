#!/usr/bin/env bash

if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  sudo apt-get update
fi

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  brew update
fi
