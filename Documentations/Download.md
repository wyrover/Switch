![Switch Header](Images/SwitchNativeC++port.png)
______________________________________________________________________________________________
| [Home](Home.md) | [Gallery](Gallery.md) | [Examples](Examples.md) | [Download](Download.md) | [Documentation](Documentation.md) | [Project](https://sourceforge.net/projects/switchpro) | [Source](https://github.com/gammasoft71/switch) | [License](License.md) | [Contact](Contact.md) | [GAMMA Soft](https://gammasoft71.wixsite.com/gammasoft) |
______________________________________________________________________________________________

# Download Switch 0.3.2

You can download latest stable version on SourceForge

[![Download Portable C++ Framework](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/switchpro/files/latest/download)

# Switch Development

Or download latest development version on GitHub.

[Sources on GitHub](https://github.com/gammasoft71/Switch)

# Installation

## Windows 10 or later

1. Install Microsoft Visual Studio 2017 Community
   In order to build Switch, you first need download and install Microsoft Visual Studio 2017 community from [https://www.visualstudio.com](https://www.visualstudio.com).

2. Install CMake
   After Microsoft Visual Studio, to build Switch, you need to install the latest version cmake from [https://cmake.org/download/](https://cmake.org/download/)
   *Remarks: Verify if you can execute cmake --version in "Developer Command Prompt for VS 2017", if it's no, add cmake install directory to your path.*

3. Install Doxygen
   After CMake, to generate Switch documentation, you need to install the latest version Doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
   *Remarks: Verify if you can execute doxygen --version in "Developer Command Prompt for VS 2017", if it's no, add doxygen install directory to your path.*

4. After installing Microsoft Visual Studio, Cmake and Doxygen, do the following in "Developer Command Prompt for VS 2017" to Build and install Switch :
```
cd C:\Users\YourName\Switch\
install.bat
```
   *Remarks, this operation depand of your hardware and can be very long*

5. Enjoy and be creative with Switch ;-)

### Remarks

* Switch installer set cmake variable CMAKE_INSTALL_PREFIX to "C:/usr/local" for generate, build and install Switch.
* When install is complete you can find installed Switch files in folder "C:/usr/local".
* To build your own project using Switch, don't miss to set cmake variable CMAKE_INSTALL_PREFIX to "C:/usr/local"; otherwise cmake don't find Switch libraries and include files. See cmake documentation (http://cmake.org/documentation) for more information.
* type install /? to view usage help page.

## macOS 10.12 or later

1. Install Xcode
   In order to build Switch, you first need download and install Xcode from App Store and install "Commands line tools".
   *Remarks: Verify if you can execute clang --version in terminal.*

2. Install Homebrew
   After Xcode, to build Switch, you need to install the latest version cmake, curl, doxygen, jpeg, pnglib and zlib, ... 
   The easiest way to get this is from Homebrew (http://brew.sh/).

3. After installing brew, do the following in "Terminal" to Build and install Switch :

```
cd /Users/YourName/Switch
./install.sh
```
   *Remarks, this operation depand of your hardware and can be very long*

4. Enjoy and be creative with Switch ;-)

## Ubuntu 16.04 or later

1. Do the following in "Terminal" to Build and install Switch :

```
cd /home/YourName/Switch
./install.sh
```
*Remarks, this operation depend of your hardware and can be very long*

2. Enjoy and be creative with Switch ;-)

## CentOS 7 or later

1. Do the following in "Terminal" to Build and install Switch :
  
```
cd /home/YourName/Switch
./install.sh
```
*Remarks, this operation depand of your hardware and can be very long*
  
2. Enjoy and be creative with Switch ;-)

## Other linux Distribution

1. Install clang 4.0.0 or later
   In order to build Switch, you first need download and install clang 4.0.0 or later.
   *Remarks: Verify if you can execute clang --version in terminal.*

2. Install CMake 
   After clang, to build Switch, you need to install the latest version cmake from https://cmake.org/download/
   *Remarks: Verify if you can execute cmake --version in terminal.*

3. Install Doxygen
   After CMake, to generate Switch documentation, you need to install the latest version Doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
   *Remarks: Verify if you can execute doxygen --version in terminal.*

4. After installing Doxygen, you need to install gtkmm 3 on your system. See https://developer.gnome.org/gtkmm-tutorial/stable/chapter-installation.html for more information.
  
5. After installing gtkmm, do the following in "Terminal" to Build and install Switch :
  
```
cd /home/YourName/Switch
./install.sh
```
   *Remarks, this operation depand of your hardware and can be very long*
  
5. Enjoy and be creative with Switch ;-)

# Build and run your first Switch application

After downloading and install Switch you are ready to build and run your first application. We will call it SwitchConsole (or what you want).
This application is very simple and it composed of 2 files :
​
A source file SwitchConsole.cpp :

```c++
#include <Switch/Switch>
 
using namespace System;
 
namespace SwitchConsole {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("My first switch application");
      Console::WriteLine();
    }
  };
}
 
_startup (SwitchConsole::Program)
```
A cmake file CMakeLists.txt :

```cmake
cmake_minimum_required(VERSION 3.2)
 
Project(SwitchConsole)
 
find_package(Switch REQUIRED)
add_executable(SwitchConsole SwitchConsole.cpp)
target_link_libraries(SwitchConsole Switch.Core)
```

## Build and Run on Windows

To build this wonderful application, open "Developer Command Prompt for VS 2017" and type following lines:

```
cd C:\Users\YourName\Projects\SwitchConsole
mkdir bin
cd bin
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ..
```
The SwitchConsle.sln file was generate, open it with VisualStudio 2017. Select SwitchConsole project and type Ctrl+F5 to build and run your first application.

## Build and Run on macOS

To build this wonderful application, open "Terminal" and type following lines:

```
cd /Users/YourName/Projects/SwitchConsole
mkdir bin
cd bin
cmake -G "Xcode" ..
```
The SwitchConsle.xcodeproj file was generate, open it with Xcode. Select SwitchConsole project and type Cmd+R to build and run your first application.

## Build and Run on Linux

To build this wonderful application, open "Terminal" and type following lines:

```
cd /home/YourName/Projects/SwitchConsole
mkdir bin
cd bin
cmake -G ..
```
The makefile was generate, in the same "Terminal" type following lines to build and run your first application:

```
make
./SwitchConsole
```

### Remarks

* If your application is unit tests application, is the same procedure but you must replace the line "target_link_libraries(SwitchConsole Switch.Core)" by "target_link_libraries(SwitchConsole Switch.TUnit.Main)" if you don't have your own main entry point; or "target_link_libraries(SwitchConsole Switch.TUnit)" it you have your own main entry point in CMakeLists.txt file.
* ​If your application is GUI application, is the same procedure but you must replace the line "add_executable(SwitchConsole SwitchConsole.cpp)" by "add_executable(SwitchConsole ${SWITCH_GUI} SwitchConsole.cpp)" and replace the line "target_link_libraries(SwitchConsole Switch.Core)" by "target_link_libraries(SwitchConsole Switch.Forms)" in CMakeLists.txt file.

______________________________________________________________________________________________
© 2010 - 2017 by GAMMA Soft.
