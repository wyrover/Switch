# Pcf
Portable C++ Framework

#The Pcf Libraries are...
- a collection of C++ classes libraries, similar to the .NET Framework;
- written in efficient, modern C++14;
- and highly portable and available on many different platforms (Windows, Mac Os X, Linux);

# Libraries
The framework is composed of 3 libraries :
- Pcf.Core : The Pcf.Core library is a library of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
- Pcf.Drawing : The Pcf.Drawing library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
- Pcf.Forms : The Pcf.Forms library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
- Pcf.TUnit : The Pcf.TUnit library contains unit testing framework.

#Namespace
- Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
- Pcf::System::Collections namespace contain types that define various standard, specialized, and generic collection objects.
- Pcf::System::Collections::Concurrent provides several thread-safe collection classes that should be used in place of the corresponding types in the System.Collections and System.Collections.Generic namespaces whenever multiple threads are accessing the collection concurrently.
- Contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
- Contains classes that can be used as collections in the object model of a reusable library.
- Contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
- Provides classes that are used to implement the run-time and design-time behavior of components and controls.
- Contains types that enable you to interact with system processes, event logs, and performance counters. Child namespaces contain types to interact with code analysis tools, to support contracts, to extend design-time support for application monitoring and instrumentation, to log event data using the Event Tracing for Windows (ETW) tracing subsystem, to read to and write from event logs and collect performance data, and to read and write debug symbol information.￼￼
- Contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
- Provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the Pcf::System::Drawing namespace.
- Contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as StringInfo and TextInfo provide advanced globalization functionalities, including surrogate support and text element processing.
- Contain types that support input and output, including the ability to read and write data to streams either synchronously or asynchronously, to compress data in streams, to create and use isolated stores, to map files to an application's logical address space, to store multiple data objects in a single container, to communicate using anonymous or named pipes, to implement custom logging, and to handle the flow of data to and from serial ports.
- Contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
- Contain types that support queries that use Language-Integrated Query (LINQ). This includes types that represent queries as objects in expression trees.
- Contains classes for playing sound files and accessing sounds provided by the system.
- Contain classes that provide a simple programming interface for a number of network protocols, programmatically access and update configuration settings for the Pcf::System::Net namespaces, define cache policies for web resources, compose and send e-mail, represent Multipurpose Internet Mail Exchange (MIME) headers, access network traffic data and network address information, and access peer-to-peer networking functionality. Additional child namespaces provide a managed implementation of the Windows Sockets (Winsock) interface and provide access to network streams for secure communications between hosts.
- Provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
- Provides a managed implementation of the WebSocket interface for developers.
- Contain types that support an application's interaction with the common language runtime, and types that enable features such as application data caching, advanced exception handling, application activation within application domains, COM interop, distributed applications, serialization and deserialization, and versioning.
- Contains classes that can be used for serializing and deserializing objects.
- Provides the underlying structure of the common language runtime security system.
- Contains classes that represent ASCII and Unicode character encodings; abstract base classes for converting blocks of characters to and from blocks of bytes; and a helper class that manipulates and formats String objects without creating intermediate instances of String.
- Provides classes and interfaces that enable multithreaded programming.
- Provides types that simplify the work of writing concurrent and asynchronous code. The main types are System::Threading::Tasks::Task which represents an asynchronous operation that can be waited on and cancelled, and System::Threading::Tasks::Task<TResult>, which is a task that can return a value. The System::Threading::Tasks::TaskFactory class provides static methods for creating and starting tasks, and the System::Threading::Tasks::TaskScheduler class provides the default thread scheduling infrastructure.
- Provides several important Windows Presentation Foundation (WPF) base element classes, various classes that support the WPF property system and event logic, and other types that are more broadly consumed by the WPF core and framework.
- Contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
- Contains classes for rendering controls and other Windows user interface (UI) elements with visual styles in operating systems that support them.
- Provide Microsoft specific classes.
- Provides two types of classes: those that handle events raised by the operating system and those that manipulate the system registry.
- Contains a unit test framework.

#Objectives and Mission

- Pcf is a powerful, yet easy to use platform to build your applications upon
- Pcf allows you to build highly portable applications (write once – compile and run anywhere)
- Pcf is modular and scalable from embedded applications
- Pcf provides consistent, comprehensive and comprehensible programming interfaces
- Pcf is written in fast, efficient C++14.
- Pcf favors simplicity over complexity ("as simple as possible, but not simpler")
- Pcf aims for consistency in design, coding style and documentation
- Pcf emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability
- Pcf aims to make C++ programming fun again Guiding Principles
- Strong focus on code quality, style, consistency and code readability –all code must satisfy our coding style guide
- Strong focus on tests (automated unit tests with high coverage)
- Build on top of solid foundations – use existing proven C libraries (e.g. libcurl, icu, zlib, SQLite) where it makes sense
