rm  -r bin
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/cmake
mkdir -p bin/Examples
mkdir -p bin/ThirdParties

brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

cd bin/ThirdParties
cmake -G "Xcode" ../../ThirdParties
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd ..
cmake -G "Xcode" ..
xcodebuild -target documentation -configuration Debug
open Help/html/index.html
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd Examples
cmake -G "Xcode" ../../Examples
#xcodebuild -target ALL_BUILD -configuration Release
open Examples.xcodeproj
cd ../..
