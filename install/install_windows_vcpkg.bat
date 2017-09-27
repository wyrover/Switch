"%1\vcpkg" install curl gtest libjpeg-turbo zlib libpng
"%1\vcpkg" integrate install

call install\install_windows_generate_and_build.bat "" "-DCMAKE_TOOLCHAIN_FILE=%1/scripts/buildsystems/vcpkg.cmake" %2
