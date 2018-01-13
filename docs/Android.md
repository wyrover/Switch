[![Switch Header](Pictures/SwitchNativeC++port.png)](https://gammasoft71.wixsite.com/switch)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Gammasoft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|---------------------------------------------------------|

# android 6.0

## Download

[https://developer.android.com/ndk/downloads](https://developer.android.com/ndk/downloads)

## API level choice

See the Following table to find the corresponding level to the android version :

[https://developer.android.com/ndk/guides/stable_apis.html](https://developer.android.com/ndk/guides/stable_apis.html)

The level 23 corresponds to android 6.0.

## Architecture choice

Whe would build for 32 and 64 bits target :

* **arm** for 32 bits
* **arm64** for 64 bits

## Standalone toolchains creation

### 32 bits toolchain

```bash
$NDK/build/tools/make_standalone_toolchain.py --arch=arm --api=24 --stl=libc++ --install-dir={where-you-want}/android-toolchain-arm-24
```

### 64 bits toolchain

```bash
$NDK/build/tools/make_standalone_toolchain.py --arch=arm64 --api=24 --stl=libc++ --install-dir={where-you-want}/android-toolchain-arm64-24
```

### Toolchain cmake

```cmake
cmake_minimum_required (VERSION 3.2)

# Standard settings
set(CMAKE_LIBRARY_ARCHITECTURE "arm") 
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)
set(UNIX True)
set(ANDROID True)

#set toolchain components
set(CMAKE_C_COMPILER /Developer/android-toolchain-arm64-api24/bin/aarch64-linux-android-clang)
set(CMAKE_CXX_COMPILER /Developer/android-toolchain-arm64-api24/bin/aarch64-linux-android-clang++)

add_definitions(-D__ANDROID__)

```

______________________________________________________________________________________________

© 2010 - 2018 by Gammasoft.
