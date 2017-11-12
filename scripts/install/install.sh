echo "Install Switch libraries version $switch_version, copyright GAMMA Soft, 2017"
echo ""

# Detecting linux distribution
OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]]; then OSTYPE=`lsb_release -si`; fi

# install needed packages and libraries by known distribution
case "$OSTYPE" in
  *"CentOS"*) sudo yum update; sudo yum install clang cmake3 doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel uuid-devel gtkmm30-devel -y;;
  *"Darwin"*) sudo chown -R $(whoami) /usr/local/share; brew update; brew install cmake doxygen curl jpeg libpng zlib;;
  *"Debian"*) sudo apt update; sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y;;
  *"elementary"*) sudo apt update; sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libssl-dev libx11-dev uuid-dev zlibc -y;;
  *"Fedora"*) sudo yum update; sudo yum install clang cmake doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel libuuid-devel uuid-devel gtkmm30-devel -y;;
  *"LinuxMint"*) sudo apt update; sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y;;
  *"RedHat"*) sudo yum update; sudo yum install clang cmake doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel libuuid-devel uuid-devel gtkmm30-devel -y;;
  *"Ubuntu"*) sudo apt update; sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y;;
esac

# set clang as default compiler
if [[ "$OSTYPE" != *"Darwin"* ]]; then 
  export CC=/usr/bin/clang
  export CXX=/usr/bin/clang++
fi

# create build folders
mkdir -p build/3rdparty
mkdir -p build/examples

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release
cmake --build . -- -j8
sudo cmake --build . --target install
cd ../..

# generate, build and install Switch
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . -- -j8
sudo cmake --build . --target install
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j8
sudo cmake --build . --target install
cd ..

# generate and launch examples
cd build/examples
if [[ "$OSTYPE" == *"Darwin"* ]]; then 
  cmake ../../examples -G "Xcode"
  open build/examples/Examples.xcodeproj
cd ../..
else
  cmake ../../examples -DCMAKE_BUILD_TYPE=Debug
  cd build/examples
  echo 
  echo You can now build and execute examples.
  echo 
  echo Type following commands to build and execute HelloWorld :
  echo cmake --build . --target HelloWorld
  echo Debug/HelloWorld
  echo 
  echo This example produces the following output:
  echo Hello, World!
  echo
fi
