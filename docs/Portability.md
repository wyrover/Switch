![Switch Header](Pictures/SwitchNativeC++port.png)

| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Downloads](Downloads.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
|-----------------|-----------------------|-------------------------|-------------------------|-----------------------------------|-------------------------------------------------------|-------------------------------------------------|-----------------------|-----------------------|---------------------------------------------------------|

The Portability section provide informations about Operating System suported, Compilers and Development Environment tools.

# Operating System Supported

Actualy Switch run on Windows, macOS and Linux Operating System.

## Windows 7 - 32 and 64 bits or later

[![Windows](Pictures/OS/Windows.png)](https://www.microsoft.com/windows)

## macOS 10.11.5 (OS X El Capitan) or later

[![macOS](Pictures/OS/macOS.jpg)](https://www.apple.com/macos/)

## Linux - 32 and 64 bits

### CentOS 7 or later

[![CentOS](Pictures/OS/CentOS.png)](https://www.centos.org)

### Debian 9.2.1 or later

[![Debuan](Pictures/OS/Debian.png)](https://www.debian.org)

### Elementary OS 0.4 or later

![Elementary OS](Pictures/OS/ElementaryOS.png)

### Fedora 26 or later

![Fedora](Pictures/OS/Fedora.png)

### LinuxMint 18.2 or later

![LinuxMint](Pictures/OS/LinuxMint.png)

### Redhat 7.4 or later

![Redhat](Pictures/OS/Redhat.png)

### Ubuntu 16.04 or later

![Ubuntu](Pictures/OS/Ubuntu.png)

## Other distribution (manually installation)

![Linux](Pictures/OS/Linux.png)

# Tests and coverage

Switch is every time tested with Continuous Integration tools.

## AppVeyor

![AppVeyor](Pictures/CI/AppVeyor.png)

## Travis CI

![TravisCI](Pictures/CI/TravisCI.png)

## Codecov

![Codecov](Pictures/CI/Codecov.png)

# Development Environment Tools

With CMake, Switch support many Development Environment Tools.

## Microsoft Visual C++ 2015 or later

![VisualStudio](Pictures/DevTools/VisualStudio.png)

## XCode 8.3 or later

![Xcode](Pictures/DevTools/Xcode.png)

## CLion 2017.2 or later

![CLion](Pictures/DevTools/CLion.png)

## Eclipse CDT 4.0 or later

![EclipseCDT](Pictures/DevTools/EclipseCDT.png)

## Code::Blocks 13.12 or later

![CodeBlocks](Pictures/DevTools/CodeBlocks.png)

## KDevelop 3 or later

![KDevelop](Pictures/DevTools/KDevelop.png)

## CodeLite 11 or later

![CodeLite](Pictures/DevTools/CodeLite.png)

## Qt Editor

![Qt](Pictures/DevTools/Qt.png)

## Standard Unix makefile

![LinuxMakefile](Pictures/DevTools/LinuxMakefile.png)

# Compilers

The compilers listed below are supported with Switch :

* MSVC 2015 or later
* clang 3.9 or later 
<!--* GCC 6 or later-->

# Native

Switch has a thin layer by library if needed to abstract operating system. This layer is called naturally **Native**.

For add a new Operating System, you juste have to implement Native api for the new target Operating System.

## Native API by library

[Switch.Core](../src/Switch.Core/src/Native/Api.hpp)

[Switch.System](../src/Switch.System/src/Native/Api.hpp)

[Switch.System.Drawing](../src/Switch.System.Drawing/src/Native/Api.hpp)

[Switch.System.Windows.Forms](../src/Switch.System.Windows.Forms/src/Native/Api.hpp)

______________________________________________________________________________________________

© 2010 - 2017 by GAMMA Soft.
