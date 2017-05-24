echo "Install Pcf libraries version 0.2.0, copyright GAMMA Soft, 2017"
echo ""

rm  -r Build
sudo mkdir /usr/local/cmake
sudo chmod 777 /usr/local/bin
sudo chmod 777 /usr/local/cmake
sudo chmod 777 /usr/local/include
sudo chmod 777 /usr/local/lib
# --> To remove when fltk removed from project
sudo chmod 777 /usr/local/share
sudo chmod 777 /usr/local/share/man
sudo chmod 777 /usr/local/share/man/man1
sudo chmod 777 /usr/local/share/man/man3
sudo chmod 777 /usr/local/share/man/man6
sudo chmod 777 /usr/local/share/applications
sudo chmod 777 /usr/local/lib64
# <--
mkdir -p Build/Examples
mkdir -p Build/ThirdParties

sudo yum update
sudo yum install clang cmake doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel uuid-devel gtkmm30-devel

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

cd Build/ThirdParties
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../ThirdParties 
make install -j6

cd ..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make documentation -j6
xdg-open Help/html/index.html &
make install -j6

cd Examples
#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../Examples
#make -j6
cd ../..

