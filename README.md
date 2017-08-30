![GitHub Logo](Documentations/Images/SwitchNativeC++port.png)
______________________________________________________________________________________________________________

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) 
[![Build Status](https://travis-ci.org/yfiumefreddo/Pcf.svg)](https://travis-ci.org/yfiumefreddo/Pcf) 
[![Download Portable C++ Framework](https://sourceforge.net/sflogo.php?type=8&group_id=2794431)](https://sourceforge.net/p/pcfpro/)

# The Switch framework are...
- a collection of native C++ classes libraries, similar to the .NET Framework;
- written in efficient, modern C++14;
- and highly portable and available on many different platforms (Windows, Mac Os X, Linux);

![GitHub Logo](Documentations/Images/SwitchArchitecture.png)

# Libraries
The framework is composed of 4 libraries :
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

sw_startup (HelloWorld::Program)
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
      button.Click += sw_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World!");
      };
      
      Form form;
      form.Text = "Hello World Form";
      form.Controls().Add(button);
      
      Application::Run(form);
    }
  };
}

sw_startup (HelloWorld::Program)
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

  sw_test (HelloWorldTest, CreateStringFromLiteral)
  sw_test (HelloWorldTest, CreateStringFromChar32Array)
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

# Download Switch 0.2.1
You can download latest stable version on SourceForge

[![Download Portable C++ Framework](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/pcfpro/files/latest/download)

# Install
Before running examples you must install Switch. To install it read See [Install.md](Install.md) file.

# Switch Web Site
For more information see https://gammasoft71.wixsite.com/switch
