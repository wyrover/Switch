#!/usr/bin/env sh

# generate Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cd ..

# setup git
git config --global user.email "travis@travis-ci.org"
git config --global user.name "Travis CI"

# Clone switch-doc
if [ -d "build/ReferenceGuide" ]; then rm -r -f build/ReferenceGuide; fi
git clone https://github.com/gammasoft71/switch-doc build/ReferenceGuide

# Generating documentation
cd build
cmake --build . --target Switch.ReferenceGuide
cd ..

# Publishing documentation
cd build/ReferenceGuide

# Publishing documentation
git add --all
git commit -m "Generate Reference Guide:  $TRAVIS_BUILD_NUMBER"

git remote add origin-pages https://${GH_TOKEN}@github.com/gammasoft71/switch-doc.git > /dev/null 2>&1
git push --quiet --set-upstream origin-pages gh-pages
