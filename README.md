# Pcf
Portable C++ Framework

# The Pcf Libraries are...
- a collection of native C++ classes libraries, similar to the .NET Framework;
- written in efficient, modern C++14;
- and highly portable and available on many different platforms (Windows, Mac Os X, Linux);

<<<<<<< HEAD
![GitHub Logo](Libraries/Pcf/Core/Images/Pcf.png)

#Libraries
=======
![GitHub Logo](Documentations/Images/Pcf.png)

# Libraries
>>>>>>> develop
The framework is composed of 4 libraries :
- **Pcf.Core** : The Pcf.Core library is a library of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
- **Pcf.Drawing** : The Pcf.Drawing library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
- **Pcf.Forms** : The Pcf.Forms library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
- **Pcf.TUnit** : The Pcf.TUnit library contains unit testing framework.

<<<<<<< HEAD
#Examples
The classic first application 'Hello World'.

Console:
=======
# Examples
The classic first application 'Hello World'.

## Console
HelloWorld.cpp:
>>>>>>> develop
```
#include <Pcf/Pcf>

using namespace System;

namespace HelloWorld {
  class Program {
  public:
    // The main entry point for the application.
<<<<<<< HEAD
    static void Main() {
=======
    static void Main(const Array<string>& args) {
>>>>>>> develop
      Console::WriteLine("Hello, World!");
    }
  };
}

pcf_startup (HelloWorld::Program)
```

<<<<<<< HEAD
Forms:
=======
CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.5)

Project(HelloWorld)
find_package(Pcf REQUIRED)
add_executable(HelloWorld HelloWorld.cpp)
target_link_libraries(HelloWorld Pcf.Core)
```

## Forms
HelloWorldGui.cpp:
>>>>>>> develop
```
#include <Pcf/Pcf>

using namespace System;
using namespace System::Windows::Forms;

<<<<<<< HEAD
namespace HelloWorld {
=======
namespace HelloWorldGui {
>>>>>>> develop
  class MainForm : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(MainForm());
    }
    
    MainForm() {
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(400, 200);
      this->ClientSize = System::Drawing::Size(300, 300);
      this->Text = "My first application";
      
      this->label.Parent = *this;
      this->label.Text = "Hello, World!";
      this->label.AutoSize = true;
      this->label.Font = System::Drawing::Font("Arial", 46, System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic);
      this->label.ForeColor = System::Drawing::Color::Green;
      this->label.Location = System::Drawing::Point(5, 100);
    }
    
  private:
    Label label;
  };
}

<<<<<<< HEAD
pcf_startup (HelloWorld::MainForm)
```

TUnit :
=======
pcf_startup (HelloWorldGui::MainForm)
```

CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.5)

Project(HelloWorldGui)
find_package(Pcf REQUIRED)
add_executable(HelloWorldGui WIN32 HelloWorldGui.cpp)
target_link_libraries(HelloWorldGui Pcf.Forms)
```

## TUnit
HelloWorldTest.cpp:
>>>>>>> develop
```
#include <Pcf/Pcf>

using namespace System;
using namespace TUnit;

namespace UnitTests {
  class HelloWorldTest : public TestFixture {
<<<<<<< HEAD
  public:
    // The main entry point for the application.
    static int Main(const Array<string>& args) {
      return TUnit::UnitTest(args).Run();
    }
    
  protected:
    void SetString() {
      string s = "Hello, World!";
      Assert::AreEqual("Hello, World!", s, pcf_current_information);
    }
  };

  pcf_test(HelloWorldTest, SetString);
}

pcf_startup (UnitTests::HelloWorldTest)
```

#Namespace
=======
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
```
cmake_minimum_required(VERSION 3.5)

Project(HelloWorldTest)
find_package(Pcf REQUIRED)
add_executable(HelloWorldTest HelloWorldTest.cpp)
target_link_libraries(HelloWorldTest Pcf.TUnit.Main)
```

# Namespace
>>>>>>> develop
- **Pcf::System** namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
- **Pcf::System::Collections** namespace contain types that define various standard, specialized, and generic collection objects.
- **Pcf::System::Collections::Concurrent** provides several thread-safe collection classes that should be used in place of the corresponding types in the System.Collections and System.Collections.Generic namespaces whenever multiple threads are accessing the collection concurrently.
- **Pcf::System::Collections::Generic** namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
- **Pcf::System::Collections::ObjectModel** namespace contains classes that can be used as collections in the object model of a reusable library.
- **Pcf::System::Collections::Specialized** namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
- **Pcf::System::ComponentModel** namepsace provides classes that are used to implement the run-time and design-time behavior of components and controls.
- **Pcf::System::Diagnostics** namespace contains types that enable you to interact with system processes, event logs, and performance counters. Child namespaces contain types to interact with code analysis tools, to support contracts, to extend design-time support for application monitoring and instrumentation, to log event data using the Event Tracing for Windows (ETW) tracing subsystem, to read to and write from event logs and collect performance data, and to read and write debug symbol information.
- **Pcf::System::Drawing** namespace contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
- **Pcf::System::Drawing::Imaging** namepsace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the Pcf::System::Drawing namespace.
- **Pcf::System::Globalization** namepsace contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as StringInfo and TextInfo provide advanced globalization functionalities, including surrogate support and text element processing.
- **Pcf::System::IO** namepsace contain types that support input and output, including the ability to read and write data to streams either synchronously or asynchronously, to compress data in streams, to create and use isolated stores, to map files to an application's logical address space, to store multiple data objects in a single container, to communicate using anonymous or named pipes, to implement custom logging, and to handle the flow of data to and from serial ports.
- **Pcf::System::IO::Ports** namepsace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
- **Pcf::System::Linq** namespace contain types that support queries that use Language-Integrated Query (LINQ). This includes types that represent queries as objects in expression trees.
- **Pcf::System::Media** namepsace contains classes for playing sound files and accessing sounds provided by the system.
- **Pcf::System::Net** namepsace contain classes that provide a simple programming interface for a number of network protocols, programmatically access and update configuration settings for the Pcf::System::Net namespaces, define cache policies for web resources, compose and send e-mail, represent Multipurpose Internet Mail Exchange (MIME) headers, access network traffic data and network address information, and access peer-to-peer networking functionality. Additional child namespaces provide a managed implementation of the Windows Sockets (Winsock) interface and provide access to network streams for secure communications between hosts.
- **Pcf::System::Net::Sockets** namepsace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
- **Pcf::System::Net::WebSockets** namepsace provides a managed implementation of the WebSocket interface for developers.
- **Pcf::System::Runtime** namepsace contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
- **Pcf::System::Runtime::Serialization** namepsace contains classes that can be used for serializing and deserializing objects.
- **Pcf::System::Security** namepsace provides the underlying structure of the common language runtime security system.
- **Pcf::System::Text** namepsace contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats String objects without creating intermediate instances of String.
- **Pcf::System::Threading** namepsace provides classes and interfaces that enable multithreaded programming.
- **Pcf::System::Threading::Tasks** namepsace provides types that simplify the work of writing concurrent and asynchronous code. The main types are System::Threading::Tasks::Task which represents an asynchronous operation that can be waited on and cancelled, and System::Threading::Tasks::Task< TResul t>, which is a task that can return a value. The System::Threading::Tasks::TaskFactory class provides static methods for creating and starting tasks, and the System::Threading::Tasks::TaskScheduler class provides the default thread scheduling infrastructure.
- **Pcf::System::Windows** namepsace provides several important Windows Presentation Foundation (WPF) base element classes, various classes that support the WPF property system and event logic, and other types that are more broadly consumed by the WPF core and framework.
- **Pcf::System::Windows::Forms** namepsace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
- **Pcf::System::Windows::Forms::VisualStyles** namepsace contains classes for rendering controls and other Windows user interface (UI) elements with visual styles in operating systems that support them.
- **Pcf::Microsoft** nampsace provide Microsoft specific classes.
- **Pcf::Microsoft::Win32** namepsace provides two types of classes: those that handle events raised by the operating system and those that manipulate the system registry.
- **Pcf::TUnit** namepsace contains a unit test framework.

# Objectives and Mission
- **Pcf** is a powerful, yet easy to use platform to build your applications upon
- **Pcf** allows you to build highly portable applications (write once – compile and run anywhere)
- **Pcf** is modular and scalable from embedded applications
- **Pcf** provides consistent, comprehensive and comprehensible programming interfaces
- **Pcf** is written in fast, efficient C++14.
- **Pcf** favors simplicity over complexity ("as simple as possible, but not simpler")
- **Pcf** aims for consistency in design, coding style and documentation
- **Pcf** emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability
- **Pcf** aims to make C++ programming fun again Guiding Principles
- Strong focus on code quality, style, consistency and code readability –all code must satisfy our coding style guide
- Strong focus on tests (automated unit tests with high coverage)
- Build on top of solid foundations – use existing proven C libraries (e.g. Curl, rs232, zlib,...) where it makes sense


