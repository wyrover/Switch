# create build folders
mkdir -p build/3rdparty
mkdir -p build/examples

# generate, build and install 3rdparty
cd build/3rdparty
cmake -DCMAKE_BUILD_TYPE=Release ../../3rdparty
cmake --build . -- -j$(nproc)
sudo cmake --build . --target install -- -j$(nproc)
cd ../..

# generate, build and install witch
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . -- -j$(nproc)
sudo cmake --build . --target install -- -j$(nproc)
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . -- -j$(nproc)
sudo cmake --build . --target install -- -j$(nproc)
cd ..

# generate examples
cd build/examples
cmake -DCMAKE_BUILD_TYPE=Debug ../../examples
cd ../..

# launch examples
cd build/examples
echo 
echo You can now build and execute examples.
echo 
echo For example type following commands to build and execute HelloWorld :
echo cmake --build . --target HelloWorld
echo Debug/HelloWorld
echo 
echo This example produces the following output:
echo Hello, World!
echo
