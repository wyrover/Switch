echo "Install Switch libraries version $switch_version, copyright GAMMA Soft, 2017"
echo ""

# Detecting linux distribution
OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"Darwin"* ]] && [[ "$OSTYPE" != *"MINGW64"* ]]; then OSTYPE=`lsb_release -si`; fi

# install needed packages and libraries for known distribution
case "$OSTYPE" in
  *"CentOS"*) sudo yum update; sudo yum install clang cmake3 doxygen gtkmm30-devel uuid-devel -y;;
  *"Darwin"*) sudo chown -R $(whoami) /usr/local/share; brew update; brew install astyle cmake cppcheck doxygen;;
  *"Debian"*) sudo apt update; sudo apt install clang cmake doxygen libgtkmm-3.0-dev libssl-dev uuid-dev -y;;
  *"elementary"*) sudo apt update; sudo apt install clang cmake doxygen libgtkmm-3.0-dev libssl-dev uuid-dev -y;;
  *"Fedora"*) sudo yum update; sudo yum install clang cmake doxygen gtkmm30-devel libuuid-devel uuid-devel -y;;
  *"LinuxMint"*) sudo apt update; sudo apt install clang cmake doxygen libgtkmm-3.0-dev libssl-dev uuid-dev -y;;
  *"MINGW64"*) ;;
  *"RedHat"*) sudo yum update; sudo yum install clang cmake doxygen gtkmm30-devel libuuid-devel uuid-devel -y;;
  *"Ubuntu"*) sudo apt update; sudo apt install clang cmake doxygen libgtkmm-3.0-dev libssl-dev uuid-dev -y;;
esac

# set clang as default compiler
export CC=clang
export CXX=clang++

# create build folders
mkdir -p build/examples

# generate, build and install Switch
cd build
if [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake .. -G "Xcode" "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
elif [[ "$OSTYPE" == *"MINGW64"* ]]; then
  cmake .. -DCMAKE_INSTALL_PREFIX=/c/usr/local "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
else
  cmake .. -DCMAKE_BUILD_TYPE=Debug "$@"
  cmake --build . -- -j8
  sudo cmake --build . --target install
  cmake .. -DCMAKE_BUILD_TYPE=Release "$@"
  cmake --build . -- -j8
  sudo cmake --build . --target install
fi
cd ..

# generate and launch examples
cd build/examples
if [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake ../../examples -G "Xcode" "$@"
  open Examples.xcodeproj
elif [[ "$OSTYPE" == *"MINGW64"* ]]; then
  cmake ../../examples -DCMAKE_INSTALL_PREFIX=/c/usr/local "$@"
  start Examples.sln
else
  cmake ../../examples -DCMAKE_BUILD_TYPE=Debug  "$@"
  cd build/examples
  echo 
  echo You can now build and execute examples.
  echo 
  echo Type following commands to build and execute HelloWorld :
  echo cd build/examples
  echo cmake --build . --target HelloWorld
  echo Debug/HelloWorld
  echo 
  echo This example produces the following output:
  echo Hello, World!
  echo
fi
cd ../..
