CentOS 7 or later
-----------------

  1. Do the following in "Terminal" to Build and install Pcf :
     Remarks, this operation depand of your hardware and can be very long
  
     ~$ cd FolderWherePcfIsDownloaded
     
     ~$ ./install.sh
  
  2. Enjoy and be creative with Pcf ;-)

______________________________________________________________________________________________________________

Mac Os X 10.12 or later
-----------------------

  1. Install Xcode

     In order to build Pcf, you first need download and install Xcode from App Store and install "Commands line tools".
     Remarks: Verify if you can execute clang --version in terminal.

  2. Install Homebrew

     After Xcode, to build Pcf, you need to install the latest version cmake, curl, doxygen, jpeg, pnglib and zlib, ... 
     The easiest way to get this is from Homebrew (http://brew.sh/).

  3. After installing brew, do the following in "Terminal" to Build and install Pcf :
     Remarks, this operation depand of your hardware and can be very long
  
     ~$ cd FolderWherePcfIsDownloaded
     
     ~$ ./install.sh
  
  4. Enjoy and be creative with Pcf ;-)
  
______________________________________________________________________________________________________________

Ubuntu 16.04 or later
---------------------

  1. Do the following in "Terminal" to Build and install Pcf :
     Remarks, this operation depand of your hardware and can be very long
  
     ~$ cd FolderWherePcfIsDownloaded
     
     ~$ ./install.sh
  
  2. Enjoy and be creative with Pcf ;-)

______________________________________________________________________________________________________________

Windows 10 or later
-------------------

  1. Install Microsoft Visual Studio 2017 Community

     In order to build Pcf, you first need download and install Microsoft Visual Studio 2017 community from https://www.visualstudio.com.

  2. Install CMake

     After Microsoft Visual Studio, to build Pcf, you need to install the latest version cmake from https://cmake.org/download/
     Remarks: Verify if you can execute cmake --version in "Developer Command Prompt for VS 2017", if it's no, add cmake install directory to your path.

  2. Install Doxygen

     After CMake, to generate Pcf documentation, you need to install the latest version Doxygen from https://cmake.org/download/
     Remarks: Verify if you can execute doxygen --version in "Developer Command Prompt for VS 2017", if it's no, add doxygen install directory to your path.

  3. After installing Microsoft Visual Studio, Cmake and Doxygen, do the following in "Developer Command Prompt for VS 2017" to Build and install Pcf :
     Remarks, this operation depand of your hardware and can be very long
  
     C:\Users\You> cd FolderWherePcfIsDownloaded\
     C:\Users\You\FolderWherePcfIsDownloaded> install.bat
  
  4. Enjoy and be creative with Pcf ;-)
  
  ### Remarks
  * Pcf installer set cmake variable CMAKE_INSTALL_PREFIX to "C:/usr/local" for generate, build and install Pcf.
  * When install is complete you can find installed Pcf files in folder "C:/usr/local".
  * To build your own project using Pcf, don't miss to set cmake variable MAKE_INSTALL_PREFIX to "C:/usr/local"; otherwise cmake don't find Pcf libraries and include files. See cmake documentation (http://cmake.org/documentation) for more information.
  
______________________________________________________________________________________________________________

Other linux Distribution
------------------------

  1. Install clang 4.0.0 or later
  
     In order to build Pcf, you first need download and install clang 4.0.0 or later.
     Remarks: Verify if you can execute clang --version in terminal.

    2. Install CMake
    
     After clang, to build Pcf, you need to install the latest version cmake from https://cmake.org/download/
     Remarks: Verify if you can execute cmake --version in terminal.

  3. Install Doxygen

     After CMake, to generate Pcf documentation, you need to install the latest version Doxygen from https://cmake.org/download/
     Remarks: Verify if you can execute doxygen --version in terminal.

  4. After installing CMAke, do the following in "Terminal" to Build and install Pcf :
     Remarks, this operation depand of your hardware and can be very long
  
     ~$ cd FolderWherePcfIsDownloaded
     
     ~$ ./install.sh
  
  5. Enjoy and be creative with Pcf ;-)
  
