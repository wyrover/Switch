rm  -r -q build 2>/dev/null
mkdir -p build/3rdparty
cd build/3rdparty
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../../3rdparty
make all -j8
sudo make install

cd ..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
make all -j8
sudo make install
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make all -j8
sudo make install

mkdir examples
cd examples
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../../examples
cd ../..

