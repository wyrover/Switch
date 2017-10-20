sudo chown -R $(whoami) /usr/local/var/homebrew
brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

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
cmake -G "Xcode" ../../3rdparty
xcodebuild -target install -configuration Release

cd ..
cmake -G "Xcode" ..
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

mkdir examples
cd examples
cmake -G "Xcode" ../../examples
open Examples.xcodeproj
cd ../..
