sudo apt update
sudo apt install clang cmake doxygen libcurlpp-dev libgtkmm-3.0-dev libjpeg8-dev libpng-dev libssl-dev libx11-dev uuid-dev zlibc -y

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_linux_generate_and_build.sh
