echo "Install Switch libraries version $switch_version, copyright Gammasoft, 2018"
echo ""

# ________________________________________________________________________________________
#                                                             Detecting linux distribution
OSTYPE=`uname -a`
if [[ "$OSTYPE" != *"MINGW64"* ]] && [[ "$OSTYPE" != *"Darwin"* ]]; then
  OSTYPE=`lsb_release -si`;
fi

# ________________________________________________________________________________________
#                             install needed packages and libraries for known distribution
case "$OSTYPE" in
  *"Darwin"*) brew update; brew install cmake -y;;
  *"Debian"* | *"elementary"* | *"LinuxMint"* | *"Ubuntu"*) sudo apt update; sudo apt install clang cmake libgtkmm-3.0-dev libssl-dev uuid-dev -y;;
  *"CentOS"* | *"Fedora"* | *"RedHat"*) sudo yum update; sudo yum install clang cmake3 gtkmm30-devel libuuid-devel uuid-devel -y;;
esac

# ________________________________________________________________________________________
#                                                       generate, build and install Switch
mkdir -p build/examples
cd build
if [[ "$OSTYPE" == *"MINGW64"* ]]; then
  cmake .. -DCMAKE_INSTALL_PREFIX=/c/usr/local "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake .. -G "Xcode" "$@"
  cmake --build . --target install --config Debug
  cmake --build . --target install --config Release
else
  cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ "$@"
  cmake --build . -- -j 8
  sudo cmake --build . --target install
  cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ "$@"
  cmake --build . -- -j 8
  sudo cmake --build . --target install
fi
cd ..

# ________________________________________________________________________________________
#                                                             generate and launch examples
cd build/examples
if [[ "$OSTYPE" == *"MINGW64"* ]]; then
  cmake ../../examples -DCMAKE_INSTALL_PREFIX=/c/usr/local "$@"
  start Examples.sln
elif [[ "$OSTYPE" == *"Darwin"* ]]; then
  cmake ../../examples -G "Xcode" "$@"
  open Examples.xcodeproj
else
  cmake ../../examples -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ "$@"
  echo ____________________________________________________________
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
  echo Remarks: Type following command to obtain the examples target list :
  echo cd build/examples
  echo cmake --build . --target help
  echo
fi
cd ../..
