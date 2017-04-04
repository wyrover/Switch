echo "Install Pcf libraries version 0.2.0, copyright GAMMA Soft, 2017"
echo ""

rm  -r Build
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/bin
sudo chmod 777 /usr/local/cmake
sudo chmod 777 /usr/local/include
sudo chmod 777 /usr/local/lib
mkdir -p Build/Examples
mkdir -p Build/ThirdParties

sudo yum update
sudo yum install clang cmake3 libcurl-devel libjpeg-devel zlib-devel libpng-devel libx11-devel uuid-devel fltk-devel gtkmm30-devel

ln -s /usr/bin/cmake3 /usr/local/bin/cmake
ln -s /usr/bin/cpack3 /usr/local/bin/cpack

cd Build/ThirdParties
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../ThirdParties 
make install -j6

cd ..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make documentation -j6
xdg-open Help/html/index.html
make install -j6

cd Examples
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../Examples
#make -j6
cd ../..

