echo "Install Pcf libraries version 0.2.0, copyright GAMMA Soft, 2017"
echo ""

function CheckError() {
  "$@"
  local status=$?
  if [ $status -ne 0 ]; then
    echo ""
    echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" >&2
    echo "! error $status with $1 $2 $3" >&2
    echo "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" >&2
    echo ""
    exit
  fi
  return $status
}

rm  -r Build
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/cmake
mkdir -p Build/Examples
mkdir -p Build/ThirdParties

brew update
brew install cmake
brew install curl
brew install doxygen
brew install jpeg
brew install libpng
brew install zlib

cd Build/ThirdParties
cmake -G "Xcode" ../../ThirdParties
xcodebuild -target install -configuration Debug
xcodebuild -target install -configuration Release

cd ..
CheckError cmake -G "Xcode" ..
CheckError xcodebuild -target documentation -configuration Debug
CheckError open Help/html/index.html
CheckError xcodebuild -target install -configuration Debug
CheckError xcodebuild -target install -configuration Release

cd Examples
CheckError cmake -G "Xcode" ../../Examples
CheckError xcodebuild -target ALL_BUILD -configuration Release
CheckError open Examples.xcodeproj
CheckError cd ../..
