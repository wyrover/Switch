#!/bin/bash

set -ev

# ________________________________________________________________________________________
#                                                                     install cpp-coverall
brew update
brew install pyenv
eval "$(pyenv init -)"
pyenv install 2.7.6
pyenv global 2.7.6
pyenv rehash
pip install cpp-coveralls
pyenv rehash

# ________________________________________________________________________________________
#                                                                      publish to coverall
coveralls --build-root build --gcov-options '\-lp' -e build/3rdparty -e build/astyle-prefix -e build/cppcheck-prefix -e build/examples -e build/ReferenceGuide -e build/include -e build/CMakeFiles/3.9.4 -e build/CMakeFiles/feature_tests.c -e build/CMakeFiles/feature_tests.cxx
