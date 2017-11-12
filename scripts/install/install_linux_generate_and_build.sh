if [ -d ./build ]; then rm -r -f build; fi

mkdir -p build/3rdparty
mkdir -p build/examples

# generate, build and install 3rdparty
cd build/3rdparty
cmake -DCMAKE_BUILD_TYPE=Release ../../3rdparty
cmake --build . -- -j$(nproc)
sudo cmake --build . --target install -- -j$(nproc)
cd ../..

# generate, build and install witch
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make install -j$(nproc)
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j$(nproc)
sudo cmake --build . --target install -- -j$(nproc)
cd ..

# generate examples
cd build/examples
cmake -DCMAKE_BUILD_TYPE=Debug ../../examples
cd ../..

