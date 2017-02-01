echo "Install Pcf 0.2.0 on Mac os X"
echo ""

sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/cmake

brew update
brew install curl
brew install jpeg
brew install libpng
brew install zlib

rm  -r Build
mkdir Build
cd Build
mkdir ThirdParties
cd ThirdParties
cmake -G "Xcode" ../../ThirdParties
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd ..
cmake -G "Xcode" ..
xcodebuild -target documentation -configuration Debug
open Help/html/index.html
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

mkdir Examples
cd Examples
cmake -G "Xcode" ../../Examples
xcodebuild -target ALL_BUILD -configuration Release
open Examples.xcodeproj
cd ../..
