#!/usr/bin/env sh

# generate Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cd ..

# setup git
git config --global user.email "gammasoft71@gmail.com"
git config --global user.name "gammasoft71"

# Clone switch-doc
if [ -d "build/ReferenceGuide" ]; then rm -r -f build/ReferenceGuide; fi
git clone https://github.com/gammasoft71/Switch-doc.git build/ReferenceGuide

# Generating documentation
cd build
cmake --build . --target Switch.ReferenceGuide
cd ..

# Publishing documentation
cd build/ReferenceGuide

# Publishing documentation
git add --all
git commit -m "Generate Reference Guide:  $TRAVIS_BUILD_NUMBER"
git push "https://${GH_TOKEN}@github.com/gammasoft71/Switch-doc.git" master > /dev/null 2>&1 
