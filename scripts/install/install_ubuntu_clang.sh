rm  -r -q bin
mkdir -p bin/Examples
mkdir -p bin/3rdparty

sudo apt update
sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

cd bin/3rdparty
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ../../3rdparty
make all -j6
sudo make install

cd ..
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ..
make documentation -j6
xdg-open Help/html/index.html &>/dev/null &
make all -j6
sudo make install

cd Examples
#cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ../../Examples
#make all -j6
cd ../..
