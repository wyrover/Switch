#!/usr/bin/env sh

# install needed packages and libraries
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then brew install curl jpeg libpng zlib -y; fi
