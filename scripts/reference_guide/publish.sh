#!/usr/bin/env sh

# Publishing documentation
cd build/ReferenceGuide
git add --all
git commit -m "Generate Reference Guide"
git push
