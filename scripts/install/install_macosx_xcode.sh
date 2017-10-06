rm  -r bin
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/cmake
mkdir -p bin/Examples
mkdir -p bin/3rdparty

brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

cd bin/3rdparty
cmake -G "Xcode" ../../3rdparty
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd ..
cmake -G "Xcode" ..
#xcodebuild -target documentation -configuration Debug
#open Help/html/index.html
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd Examples
cmake -G "Xcode" ../../Examples
open Examples.xcodeproj
cd ../..
