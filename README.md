![GitHub Logo](Documentations/Images/Pcf-logo 190x80.png)

# Pcf
### Portable C++ Framework

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0) 
[![Build Status](https://travis-ci.org/yfiumefreddo/Pcf.svg)](https://travis-ci.org/yfiumefreddo/Pcf) 
[![Download Portable C++ Framework](https://sourceforge.net/sflogo.php?type=8&group_id=2794431)](https://sourceforge.net/p/pcfpro/)

# The Pcf Libraries are...
- a collection of native C++ classes libraries, similar to the .NET Framework;
- written in efficient, modern C++14;
- and highly portable and available on many different platforms (Windows, Mac Os X, Linux);

![GitHub Logo](Documentations/Images/Pcf.png)

# Libraries
The framework is composed of 4 libraries :
- **Pcf.Core** : The Pcf.Core library is a library of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
- **Pcf.Drawing** : The Pcf.Drawing library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
- **Pcf.Forms** : The Pcf.Forms library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
- **Pcf.TUnit** : The Pcf.TUnit library is a unit-testing framework for modern C++14. Initially ported from NUnit.

# Objectives and Mission
- **Pcf** is a powerful, yet easy to use platform to build your applications upon
- **Pcf** allows you to build highly portable applications (write once – compile and run anywhere)
- **Pcf** is modular and scalable from embedded applications
- **Pcf** provides consistent, comprehensive and comprehensible programming interfaces
- **Pcf** favors simplicity over complexity ("as simple as possible, but not simpler")
- **Pcf** aims for consistency in design, coding style and documentation
- **Pcf** emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability
- **Pcf** aims to make C++ programming fun again Guiding Principles
- Strong focus on code quality, style, consistency and code readability –all code must satisfy our coding style guide
- Strong focus on tests (automated unit tests with high coverage)
- Build on top of solid foundations – use existing proven C libraries (e.g. Curl, rs232, zlib,...) where it makes sense

# Examples
The classic first application 'Hello World'.

## Console
HelloWorld.cpp:
```c++
#include <Pcf/Pcf>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    static void Main() {
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (HelloWorld::Program)
```

CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorld)
find_package(Pcf REQUIRED)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld Pcf.Core)
```

## Forms
HelloWorldForm.cpp:
```c++
#include <Pcf/Pcf>

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
      button.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        MessageBox::Show("Hello, World!");
      };
      
      Form form;
      form.Text = "Hello World Form";
      form.Controls().Add(button);
      
      Application::Run(form);
    }
  };
}

pcf_startup (HelloWorld::Program)
```

CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldForm)
find_package(Pcf REQUIRED)
add_executable(HelloWorldForm ${PCF_GUI} HelloWorldForm.cpp)
target_link_libraries(HelloWorldForm Pcf.Forms)
```

## TUnit
HelloWorldTest.cpp:
```c++
#include <Pcf/Pcf>

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

  pcf_test (HelloWorldTest, CreateStringFromLiteral)
  pcf_test (HelloWorldTest, CreateStringFromChar32Array)
}
```

CMakeLists.txt:
```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldTest)
find_package(Pcf REQUIRED)
add_executable(HelloWorldTest HelloWorldTest.cpp)
target_link_libraries(HelloWorldTest Pcf.TUnit.Main)
```

For more Examples see [Examples](Examples)

# Download Pcf 0.2.0
You can download latest stable version on SourceForge

[![Download Portable C++ Framework](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/pcfpro/files/latest/download)

# Install
Before running examples you must install Pcf. To install it read See [Install.md](Install.md) file.

# Pcf Web Site
For more information see https://yfiumefreddo.wixsite.com/pcfpro
