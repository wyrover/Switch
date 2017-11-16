rem run registered unit tests
cd build32
ctest --output-on-failure --build-config Release
cd ..

rem run registered unit tests
cd build64
ctest --output-on-failure --build-config Release
cd ..
