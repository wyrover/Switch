@echo off

rem ______________________________________________________________________________________
rem                                                                       Clone switch-doc
if exist "build/ReferenceGuide" (
  rmdir /s /q build/ReferenceGuide
)
git clone https://github.com/gammasoft71/switch-doc build/ReferenceGuide

rem ______________________________________________________________________________________
rem                                                               Generating documentation
cd build
cmake --build . --target Switch.ReferenceGuide
cd ..

rem_______________________________________________________________________________________
rem                                                               Publishing documentation
cd build/ReferenceGuide
git add --all
git commit -m "Generate Reference Guide"
git push
