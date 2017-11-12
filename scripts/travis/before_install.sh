#!/usr/bin/env sh

# update packages manager
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then brew update; fi
