[![GitHub Logo](docs/Pictures/SwitchNativeC++port.png)](https://gammasoft71.github.io/Switch)
____________________________________________________________________________________

[![License: GPL v3](https://img.shields.io/badge/Language-c++17%20ready-blue.svg)](docs/C++17Ready.md) 
[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-brightgreen.svg)](docs/License.md) 
[![Build Status](https://travis-ci.org/gammasoft71/Switch.svg)](https://travis-ci.org/gammasoft71/Switch) 
[![Download Switch](https://img.shields.io/sourceforge/dt/switchpro.svg)](https://sourceforge.net/projects/switchpro/files/latest/download)
[![HitCount](http://hits.dwyl.io/gammasoft71/switch.svg)](http://hits.dwyl.io/gammasoft71/switch)
[![Status](https://img.shields.io/badge/Development-status-blue.svg)](docs/SwitchStatus.md) 
<!--[![Build status](https://ci.appveyor.com/api/projects/status/kjfq2sl5bc99kut6?svg=true)](https://ci.appveyor.com/project/gammasoft71/switch)-->

# The Switch framework is...
* a collection of native C++ classes libraries, similar to the .NET Framework;
* written in efficient, modern C++14;
* and highly portable and available on many different platforms (Windows, macOS, Linux);

For more information see [Switch website](https://gammasoft71.github.io/Switch) (or [markdown Documentations](./docs/Home.md)) and [Reference Guide](https://gammasoft71.github.io/Switch-doc)


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

_startup(HelloWorld::Program)
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorld)
find_package(Switch REQUIRED)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld Switch.System)
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

_startup(HelloWorld::Program)
```

CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.2)

Project(HelloWorldForm)
find_package(Switch REQUIRED)
add_executable(HelloWorldForm ${SWITCH_GUI} HelloWorldForm.cpp)
target_link_libraries(HelloWorldForm Switch.System.Windows.Forms)
```

## TUnit
HelloWorldTest.cpp:

```c++
#include <Switch/Switch>

using namespace TUnit;
using namespace System;

namespace UnitTests {
  class _test_fixture(HelloWorldTest) {
    void _test(CreateStringFromLiteral)() {
      string s = "Hello, World!";
      Assert::AreEqual("Hello, World!", s);
    }

    void _test(CreateStringFromChars)() {
      string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
      Assert::AreEqual("Hello, World!", s);
    }
  };

  _add_test(HelloWorldTest, CreateStringFromLiteral)
  _add_test(HelloWorldTest, CreateStringFromChars)
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

For more examples see [Examples](examples)

# Download and install Switch

Before running examples you must download and install Switch. To download and install it read [Downloads](https://gammasoft71.wixsite.com/switch/downloads) page or [Downloads.md](./docs/Downloads.md) file.