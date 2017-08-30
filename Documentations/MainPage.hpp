/// @mainpage Switch - Reference Guide Documentation
///
/// @section ThePcfLibrariesAreSection The Switch framework are...
///   * a collection of C++ classes libraries, similar to the .NET Framework;
///   * written in efficient, modern C++14;
///   * and highly portable and available on many different platforms;
///
/// @image HTML SwitchArchitecture.png
///
/// @section Pcfiscomposedof4librariesSection Switch is composed of 4 libraries
///   * <b>Switch.Core</b> library is a library of classes, interfaces, and value types that provide access to system functionality. It is the foundation on which c++ applications, components, and controls are built.
///   * <b>Switch.Drawing</b> library contains types that support basic GDI+ graphics functionality. Child namespaces support advanced two-dimensional and vector graphics functionality, advanced imaging functionality, and print-related and typographical services. A child namespace also contains types that extend design-time user-interface logic and drawing.
///   * <b>Switch.Forms</b> library contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system.
///   * <b>Switch.TUnit</b> library contains unit testing framework.
///
/// @section ObjectivesAndMissionSection Objectives and Mission
///   * <b>Switch</b> is a powerful, yet easy to use platform to build your applications upon
///   * <b>Switch</b> allows you to build highly portable applications (write once – compile and run anywhere)
///   * <b>Switch</b> is modular and scalable from embedded applications
///   * <b>Switch</b> provides consistent, comprehensive and comprehensible programming interfaces
///   * <b>Switch</b> favors simplicity over complexity ("as simple as possible, but not simpler")
///   * <b>Switch</b> aims for consistency in design, coding style and documentation
///   * <b>Switch</b> emphasizes source code quality, in terms of readability, comprehensiveness, consistency, style and testability
///   * <b>Switch</b> aims to make C++ programming fun again Guiding Principles
///   * Strong focus on code quality, style, consistency and code readability –all code must satisfy our coding style guide
///   * Strong focus on tests (automated unit tests with high coverage)
///   * Build on top of solid foundations – use existing proven C libraries (e.g. Curl, rs232, zlib,...) where it makes sense
///
/// @section ExamplesSection Examples
///
/// The classic first application 'Hello World'.
///
/// <b>Console</b>
///
///HelloWorld.cpp:
/// @code
/// #include <Switch/Switch>
///
/// using namespace System;
///
/// namespace HelloWorld {
///   class Program {
///   public:
///     static void Main() {
///       Console::WriteLine("Hello, World!");
///     }
///   };
/// }
///
/// sw_startup (HelloWorld::Program)
/// @endcode
///
/// CMakeLists.txt:
/// @code
/// cmake_minimum_required(VERSION 3.2)
///
/// Project(HelloWorld)
/// find_package(Switch REQUIRED)
/// add_executable(HelloWorld HelloWorld.cpp)
/// target_link_libraries(HelloWorld Switch.Core)
/// @endcode
///
/// <b>Forms</b>
///
/// HelloWorldForm.cpp:
/// @code
/// #include <Switch/Switch>
///
/// using namespace System;
/// using namespace System::Drawing;
/// using namespace System::Windows::Forms;
///
/// namespace HelloWorld {
///   class Program {
///   public:
///     static void Main() {
///       Application::EnableVisualStyles();
///
///       Button button;
///       button.Text = "Click me";
///       button.Location = Point(10, 10);
///       button.Click += sw_delegate(const object& sender, const EventArgs& e) {
///         MessageBox::Show("Hello, World!");
///       };
///
///       Form form;
///       form.Text = "Hello World Form";
///       form.Controls().Add(button);
///
///       Application::Run(form);
///     }
///   };
/// }
///
/// sw_startup (HelloWorld::Program)
/// @endcode
///
/// CMakeLists.txt:
/// @code
/// cmake_minimum_required(VERSION 3.2)
///
/// Project(HelloWorldForm)
/// find_package(Switch REQUIRED)
/// add_executable(HelloWorldForm ${SWITCH_GUI} HelloWorldForm.cpp)
/// target_link_libraries(HelloWorldForm Switch.Forms)
/// @endcode
///
/// <b>TUnit</b>
///
/// HelloWorldTest.cpp:
/// @code
/// #include <Switch/Switch>
///
/// using namespace System;
/// using namespace TUnit;
///
/// namespace UnitTests {
///   class HelloWorldTest : public TestFixture {
///   protected:
///     void CreateStringFromLiteral() {
///       string s = "Hello, World!";
///       Assert::AreEqual("Hello, World!", s);
///     }
///
///     void CreateStringFromChar32Array() {
///       string s = string(Array<char32> {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'});
///       Assert::AreEqual("Hello, World!", s);
///     }
///   };
///
///   sw_test (HelloWorldTest, CreateStringFromLiteral)
///   sw_test (HelloWorldTest, CreateStringFromChar32Array)
/// }
/// @endcode
///
/// CMakeLists.txt:
/// @code
/// cmake_minimum_required(VERSION 3.2)
///
/// Project(HelloWorldTest)
/// find_package(Switch REQUIRED)
/// add_executable(HelloWorldTest HelloWorldTest.cpp)
/// target_link_libraries(HelloWorldTest Switch.TUnit.Main)
/// @endcode
///
/// For more Examples see https://github.com/gammasoft71/Pcf/blob/master/Examples
///
/// @section DownloadSection Download Switch 0.2.1
///
/// You can download latest stable version on SourceForge
///
/// https://sourceforge.net/projects/pcfpro/files/latest/download
///
/// @section InstallSection Install
/// Before running examples you must install Switch. To install it read See https://github.com/gammasoft71/Pcf/blob/master/Install.md file.
///
/// @section PcfWebSizeSEction Switch Web Site
/// For more information see https://gammasoft71.wixsite.com/switch
