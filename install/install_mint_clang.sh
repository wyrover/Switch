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

sudo apt update
sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc

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

