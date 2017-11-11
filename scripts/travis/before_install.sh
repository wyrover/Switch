#!/usr/bin/env bash

# update packages manager
if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  #wget -O - http://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
  #sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-3.9 main"
  sudo apt-get update
elif [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  brew update
fi
