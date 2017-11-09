sudo chown -R $(whoami) /usr/local/var/homebrew
brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

if [ ! -d "/usr/local/bin" ]; then sudo mkdir -p /usr/local/bin; fi
if [ ! -d "/usr/local/cmake" ]; then sudo mkdir -p /usr/local/cmake; fi
if [ ! -d "/usr/local/include" ]; then sudo mkdir -p /usr/local/include; fi
if [ ! -d "/usr/local/lib" ]; then sudo mkdir -p /usr/local/lib; fi

sudo chown -R $(whoami) /usr/local/bin
sudo chown -R $(whoami) /usr/local/cmake
sudo chown -R $(whoami) /usr/local/include
sudo chown -R $(whoami) /usr/local/lib

if [ -d ./build ]; then rm -r -f build; fi

mkdir -p build/3rdparty
mkdir -p build/examples

# generate, build and install 3rdparty
cd build/3rdparty
cmake -G "Xcode" ../../3rdparty
cmake --build . --target install --config Release
cd ../..

# generate, build and install Switch
cd build
cmake -G "Xcode" ..
cmake --build . --target install --config Debug
cmake --build . --target install --config Release
cd ..

# generate examples
cd build/examples
cmake -G "Xcode" ../../examples
open Examples.xcodeproj
cd ../..
