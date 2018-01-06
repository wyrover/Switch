#!/usr/bin/env sh

# ________________________________________________________________________________________
#                                                                         Clone switch-doc
if [ -d "build/ReferenceGuide" ]; then rm -r -f build/ReferenceGuide; fi
git clone https://github.com/gammasoft71/switch-doc build/ReferenceGuide

# ________________________________________________________________________________________
#                                                                 Generating documentation
cd build
cmake --build . --target Switch.ReferenceGuide
cd ..

# ________________________________________________________________________________________
#                                                                 Publishing documentation
cd build/ReferenceGuide
git add --all
git commit -m "Generate Reference Guide"
git push
