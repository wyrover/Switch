Windows 10 or later
-------------------

1. Install Microsoft Visual Studio 2017 Community

In order to build Switch, you first need download and install Microsoft Visual Studio 2017 community from https://www.visualstudio.com.

2. Install CMake

After Microsoft Visual Studio, to build Switch, you need to install the latest version cmake from https://cmake.org/download/
Remarks: Verify if you can execute cmake --version in "Developer Command Prompt for VS 2017", if it's no, add cmake install directory to your path.

2. Install Doxygen

After CMake, to generate Switch documentation, you need to install the latest version Doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
Remarks: Verify if you can execute doxygen --version in "Developer Command Prompt for VS 2017", if it's no, add doxygen install directory to your path.

3. After installing Microsoft Visual Studio, Cmake and Doxygen, do the following in "Developer Command Prompt for VS 2017" to Build and install Switch :
Remarks, this operation depand of your hardware and can be very long

C:\Users\You> cd FolderWhereSwitchIsDownloaded\
C:\Users\You\FolderWhereSwitchIsDownloaded> install.bat

4. Enjoy and be creative with Switch ;-)

### Remarks
* Switch installer set cmake variable CMAKE_INSTALL_PREFIX to "C:/usr/local" for generate, build and install Switch.
* When install is complete you can find installed Switch files in folder "C:/usr/local".
* To build your own project using Switch, don't miss to set cmake variable CMAKE_INSTALL_PREFIX to "C:/usr/local"; otherwise cmake don't find Switch libraries and include files. See cmake documentation (http://cmake.org/documentation) for more information.
* type install /? to view usage help page.

______________________________________________________________________________________________________________

Mac Os X 10.12 or later
-----------------------

1. Install Xcode

In order to build Switch, you first need download and install Xcode from App Store and install "Commands line tools".
Remarks: Verify if you can execute clang --version in terminal.

2. Install Homebrew

After Xcode, to build Switch, you need to install the latest version cmake, curl, doxygen, jpeg, pnglib and zlib, ... 
The easiest way to get this is from Homebrew (http://brew.sh/).

3. After installing brew, do the following in "Terminal" to Build and install Switch :
Remarks, this operation depand of your hardware and can be very long

~$ cd FolderWhereSwitchIsDownloaded

~$ ./install.sh

4. Enjoy and be creative with Switch ;-)

______________________________________________________________________________________________________________

Ubuntu 16.04 or later
---------------------

1. Do the following in "Terminal" to Build and install Switch :
Remarks, this operation depand of your hardware and can be very long

~$ cd FolderWhereSwitchIsDownloaded

~$ ./install.sh

2. Enjoy and be creative with Switch ;-)

______________________________________________________________________________________________________________

CentOS 7 or later
-----------------

  1. Do the following in "Terminal" to Build and install Switch :
     Remarks, this operation depand of your hardware and can be very long
  
     ~$ cd FolderWhereSwitchIsDownloaded
     
     ~$ ./install.sh
  
  2. Enjoy and be creative with Switch ;-)

______________________________________________________________________________________________________________

Other linux Distribution
------------------------

  1. Install clang 4.0.0 or later
  
     In order to build Switch, you first need download and install clang 4.0.0 or later.
     Remarks: Verify if you can execute clang --version in terminal.

  2. Install CMake
    
     After clang, to build Switch, you need to install the latest version cmake from https://cmake.org/download/
     Remarks: Verify if you can execute cmake --version in terminal.

  3. Install Doxygen

     After CMake, to generate Switch documentation, you need to install the latest version Doxygen from http://www.stack.nl/~dimitri/doxygen/download.html
     Remarks: Verify if you can execute doxygen --version in terminal.

  4. After installing Doxygen, you need to install gtkmm 3 on your system. See https://developer.gnome.org/gtkmm-tutorial/stable/chapter-installation.html for more information.
  
  5. After installing gtkmm, do the following in "Terminal" to Build and install Switch :
     Remarks, this operation depand of your hardware and can be very long
  
     ~$ cd FolderWhereSwitchIsDownloaded
     
     ~$ ./install.sh
  
  5. Enjoy and be creative with Switch ;-)
  
