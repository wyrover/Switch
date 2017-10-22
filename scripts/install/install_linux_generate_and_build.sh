if [ ! -d "/usr/local/cmake" ]; then
  sudo mkdir -p /usr/local/cmake
fi

if [ ! -d "/usr/local/include" ]; then
  sudo mkdir -p /usr/local/include
fi

if [ ! -d "/usr/local/lib" ]; then
  sudo mkdir -p /usr/local/lib
fi

sudo chown -R $(whoami) /usr/local/cmake
sudo chown -R $(whoami) /usr/local/include
sudo chown -R $(whoami) /usr/local/lib

if [ -d ./build ]; then
  rm -r -f build
fi

mkdir -p build/3rdparty
cd build/3rdparty
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../3rdparty
make install -j$(nproc)

cd ..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
make install -j$(nproc)
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make install -j$(nproc)

mkdir examples
cd examples
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../examples
cd ../..

