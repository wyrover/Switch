#!/usr/bin/env sh

# Generating documentation
cd build
cmake --build . --target Switch.ReferenceGuide
cd ..
