sudo chown -R $(whoami) /usr/local/var/homebrew
brew update
brew upgrade
brew install cmake curl doxygen jpeg libpng zlib

if [ -d ./build ]; then rm -r -f build; fi

mkdir -p build/3rdparty
mkdir -p build/examples

# generate, build and install 3rdparty
cd build/3rdparty
cmake -G "Xcode" ../../3rdparty
cmake --build . --config Release
sudo cmake --build . --target install --config Release
cd ../..

# generate, build and install Switch
cd build
cmake -G "Xcode" ..
cmake --build . --config Debug
sudo cmake --build . --target install --config Debug
cmake --build . --config Release
sudo cmake --build . --target install --config Release
cd ..

# generate examples
cd build/examples
cmake -G "Xcode" ../../examples
open Examples.xcodeproj
cd ../..
