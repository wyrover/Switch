rm  -r bin
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/bin
sudo chmod 777 /usr/local/cmake
sudo chmod 777 /usr/local/include
sudo chmod 777 /usr/local/lib
mkdir -p bin/Examples
mkdir -p bin/3rdparty

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

cd bin/3rdparty
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Debug ../../3rdparty
make install -j6
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ../../3rdparty
make install -j6

cd ..
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Debug ..
#make documentation -j6
#xdg-open Help/html/index.html &
make install -j6
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ..
make install -j6

cd Examples
#cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Debug ../../Examples
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ../../Examples
cd ../..

