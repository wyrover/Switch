sudo apt update
sudo apt install clang

export CC=/usr/bin/clang
export CXX=/usr/bin/clang++

./scripts/install/install_ubuntu_gcc.sh
