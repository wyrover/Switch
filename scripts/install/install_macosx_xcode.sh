sudo chown -R $(whoami) /usr/local/var/homebrew
brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

if [ -d /usr/local/cmake ]; then
  sudo mkdir -p /usr/local/cmake
else
  sudo chown -R $(whoami) /usr/local/cmake
fi

if [ -d /usr/local/include ]; then
  sudo mkdir -p /usr/local/include
else
  sudo chown -R $(whoami) /usr/local/include
fi

if [ -d /usr/local/lib ]; then
  sudo mkdir -p /usr/local/lib
else
  sudo chown -R $(whoami) /usr/local/lib
fi

if [ -d ./build ]; then
  rm -r -f build
fi

mkdir -p build/3rdparty
cd build/3rdparty
cmake -G "Xcode" ../../3rdparty
xcodebuild -target all -configuration Release
xcodebuild -target install -configuration Release

cd ..
cmake -G "Xcode" ..
xcodebuild -target all -configuration Debug
xcodebuild -target install -configuration Debug
xcodebuild -target all -configuration Release
xcodebuild -target install -configuration Release

mkdir examples
cd examples
cmake -G "Xcode" ../../examples
open Examples.xcodeproj
cd ../..
