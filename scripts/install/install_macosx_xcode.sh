sudo chown -R $(whoami) /usr/local/var/homebrew
brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

sudo chown -R $(whoami) /usr/local/cmake
sudo chown -R $(whoami) /usr/local/include
sudo chown -R $(whoami) /usr/local/lib

rm -r -f build 2>/dev/null
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
