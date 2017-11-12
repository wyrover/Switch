#!/usr/bin/env bash

# update packages manager
if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then brew update; fi
