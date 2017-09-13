![GitHub Logo](Documentations/Images/SwitchNativeC++port.png)
____________________________________________________________________________________
[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) 
[![Build Status](https://travis-ci.org/yfiumefreddo/Pcf.svg)](https://travis-ci.org/yfiumefreddo/Pcf) 
____________________________________________________________________________________

# Switch Web Site
For more information see [https://gammasoft71.wixsite.switch](https://gammasoft71.wixsite.com/switch)

# The Switch framework is...
- a collection of native C++ classes libraries, similar to the .NET Framework;
- written in efficient, modern C++14;
- and highly portable and available on many different platforms (Windows, Mac Os X, Linux);

![GitHub Logo](Documentations/Images/SwitchArchitecture.png)

# Libraries

The framework is composed of 4 libraries:

- **Switch.Core** : The Switch.Core library is a library of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
- **Switch.Drawing** : The Switch.Drawing library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
- **Switch.Forms** : The Switch.Forms library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
- **Switch.TUnit** : The Switch.TUnit library is a unit-testing framework for modern C++14. Initially ported from NUnit.

# Objectives and Mission
- **Switch** is a powerful, yet easy to use platform to build your applications upon
- **Switch** allows you to build highly portable applications (write once – compile and run anywhere)
- **Switch** is modular and scalable from embedded applications
- **Switch** provides consistent, comprehensive and comprehensible programming interfaces
- **Switch** favors simplicity over complexity ("as simple as possible, but not simpler")
- **Switch** aims for consistency in design, coding style and documentation
- **Switch** emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability
- **Switch** aims to make C++ programming fun again Guiding Principles
- Strong focus on code quality, style, consistency and code readability –all code must satisfy our coding style guide
- Strong focus on tests (automated unit tests with high coverage)
- Build on top of solid foundations – use existing proven C libraries (e.g. Curl, rs232, zlib,...) where it makes sense

# Examples
The classic first application 'Hello World'.

## Console
HelloWorld.cpp:

```c++
#include <Switch/Switch>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

_startup (HelloWorld::Program)
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorld)
find_package(Switch REQUIRED)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld Switch.Core)
```

## Forms
HelloWorldForm.cpp:

```c++
#include <Switch/Switch>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Application::EnableVisualStyles();
      
      Button button;
      button.Text = "Click me";
      button.Location = Point(10, 10);
      button.Click += _delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World!");
      };
      
      Form form;
      form.Text = "Hello World Form";
      form.Controls().Add(button);
      
      Application::Run(form);
    }
  };
}

_startup (HelloWorld::Program)
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldForm)
find_package(Switch REQUIRED)
add_executable(HelloWorldForm ${SWITCH_GUI} HelloWorldForm.cpp)
target_link_libraries(HelloWorldForm Switch.Forms)
```

## TUnit
HelloWorldTest.cpp:

```c++
#include <Switch/Switch>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class HelloWorldTest : public TestFixture {
  protected:
    void CreateStringFromLiteral() {
      string s = "Hello, World!";
      Assert::AreEqual("Hello, World!", s);
    }

    void CreateStringFromChar32Array() {
      string s = string(Array<char32> {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'});
      Assert::AreEqual("Hello, World!", s);
    }
  };

  _test (HelloWorldTest, CreateStringFromLiteral)
  _test (HelloWorldTest, CreateStringFromChar32Array)
}
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldTest)
find_package(Switch REQUIRED)
add_executable(HelloWorldTest HelloWorldTest.cpp)
target_link_libraries(HelloWorldTest Switch.TUnit.Main)
```

For more Examples see [Examples](Examples)

# Download Switch 0.3.2

You can download latest stable version on SourceForge

[![Download Portable C++ Framework](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/switchpro/files/latest/download)

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

```shell
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

```shell
cd /Users/YourName/Switch
./install.sh
```
   *Remarks, this operation depand of your hardware and can be very long*

4. Enjoy and be creative with Switch ;-)

## Ubuntu 16.04 or later

1. Do the following in "Terminal" to Build and install Switch :

```shell
cd /home/YourName/Switch
./install.sh
```
*Remarks, this operation depend of your hardware and can be very long*

2. Enjoy and be creative with Switch ;-)

## CentOS 7 or later

1. Do the following in "Terminal" to Build and install Switch :
  
```shell
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
  
```shell
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

```shell
cd C:\Users\YourName\Projects\SwitchConsole
mkdir bin
cd bin
cmake -G "Visual Studio 15 2017 Win64" -D CMAKE_INSTALL_PREFIX:STRING="C:/usr/local" ..
```
The SwitchConsle.sln file was generate, open it with VisualStudio 2017. Select SwitchConsole project and type Ctrl+F5 to build and run your first application.

## Build and Run on macOS

To build this wonderful application, open "Terminal" and type following lines:

```shell
cd /Users/YourName/Projects/SwitchConsole
mkdir bin
cd bin
cmake -G "Xcode" ..
```
The SwitchConsle.xcodeproj file was generate, open it with Xcode. Select SwitchConsole project and type Cmd+R to build and run your first application.

## Build and Run on Linux

To build this wonderful application, open "Terminal" and type following lines:

```shell
cd /home/YourName/Projects/SwitchConsole
mkdir bin
cd bin
cmake -G ..
```
The makefile was generate, in the same "Terminal" type following lines to build and run your first application:

```shell
make
./SwitchConsole
```

### Remarks

* If your application is unit tests application, is the same procedure but you must replace the line "target_link_libraries(SwitchConsole Switch.Core)" by "target_link_libraries(SwitchConsole Switch.TUnit.Main)" if you don't have your own main entry point; or "target_link_libraries(SwitchConsole Switch.TUnit)" it you have your own main entry point in CMakeLists.txt file.
* ​If your application is GUI application, is the same procedure but you must replace the line "add_executable(SwitchConsole SwitchConsole.cpp)" by "add_executable(SwitchConsole ${SWITCH_GUI} SwitchConsole.cpp)" and replace the line "target_link_libraries(SwitchConsole Switch.Core)" by "target_link_libraries(SwitchConsole Switch.Forms)" in CMakeLists.txt file.
