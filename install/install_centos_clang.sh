rm  -r bin
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/bin
sudo chmod 777 /usr/local/cmake
sudo chmod 777 /usr/local/include
sudo chmod 777 /usr/local/lib
mkdir -p bin/Examples
mkdir -p bin/ThirdParties

sudo yum update
sudo yum install clang cmake3 doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel uuid-devel gtkmm30-devel

ln -s /usr/bin/cmake3 /usr/local/bin/cmake
ln -s /usr/bin/cpack3 /usr/local/bin/cpack

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

cd bin/ThirdParties
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ../../ThirdParties 
make install -j6

cd ..
cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ..
make documentation -j6
xdg-open Help/html/index.html &
make install -j6

cd Examples
#cmake -G "Unix Makefiles" -DCMAKE_bin_TYPE=Release ../../Examples
#make -j6
cd ../..

