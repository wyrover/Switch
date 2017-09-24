"%1\vcpkg" install curl gtest libjpeg-turbo libpng

call install\install_windows_generate_and_build.bat "" "-DCMAKE_TOOLCHAIN_FILE=%1/scripts/buildsystems/vcpkg.cmake" %2
