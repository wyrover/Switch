if [ ! -d "/usr/local/bin" ]; then sudo mkdir -p /usr/local/bin; fi
if [ ! -d "/usr/local/cmake" ]; then sudo mkdir -p /usr/local/cmake; fi
if [ ! -d "/usr/local/include" ]; then sudo mkdir -p /usr/local/include; fi
if [ ! -d "/usr/local/lib" ]; then sudo mkdir -p /usr/local/lib; fi

sudo chown -R $(whoami) /usr/local/bin
sudo chown -R $(whoami) /usr/local/cmake
sudo chown -R $(whoami) /usr/local/include
sudo chown -R $(whoami) /usr/local/lib

if [ -d ./build ]; then rm -r -f build; fi

mkdir -p build/examples

# generate, build and install witch
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make install -j$(nproc)
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --target install -- -j$(nproc)
cd ..

# generate examples
cd build/examples
cmake -DCMAKE_BUILD_TYPE=Debug ../../examples
cd ../..

