sudo apt update
sudo apt install cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y

rm  -r -q build 2>/dev/null
mkdir -p build/3rdparty
cd build/3rdparty
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../3rdparty
make all -j6
sudo make install
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../3rdparty
make all -j6
sudo make install

cd ..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
#make documentation -j6
#xdg-open Help/html/index.html &>/dev/null &
make all -j6
sudo make install
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make all -j6
sudo make install

mkdir examples
cd examples
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../examples
#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../examples
cd ../..

