sudo yum update
sudo yum install clang cmake3 doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel uuid-devel gtkmm30-devel

ln -s /usr/bin/cmake3 /usr/local/bin/cmake
ln -s /usr/bin/cpack3 /usr/local/bin/cpack

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_linux_generate_and_build.sh
