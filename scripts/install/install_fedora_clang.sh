sudo yum update
sudo yum install clang cmake doxygen libcurl-devel libjpeg-devel zlib-devel libpng-devel libX11-devel libuuid-devel uuid-devel gtkmm30-devel

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_linux_generate_and_build.sh
