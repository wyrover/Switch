/// @mainpage Switch - Reference Guide Documentation
///
/// @section TheSwitchLibrariesIsSection The Switch framework is...
///   * a collection of C++ classes libraries, similar to the .NET Framework;
///   * written in efficient, modern C++14;
///   * and highly portable and available on many different platforms;
///
/// For more information see <a href="https://gammasoft71.github.io/Switch">Switch</a> page or <a href=https://github.com/gammasoft71/switch/tree/master/docs>Documentations.md</a> file.
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
/// _startup (HelloWorld::Program)
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
///       button.Click += _delegate(const object& sender, const EventArgs& e) {
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
/// _startup (HelloWorld::Program)
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
/// using namespace TUnit::Framework;
/// using namespace System;
///
/// namespace UnitTests {
///   class _test_fixture(HelloWorldTest) {
///     void _test(CreateStringFromLiteral) {
///       string s = "Hello, World!";
///       Assert::AreEqual("Hello, World!", s);
///     }
///
///     void _test(CreateStringFromChars) {
///       string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
///       Assert::AreEqual("Hello, World!", s);
///     }
///   };
///
///   _add_test_fixture(HelloWorldTest)
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
/// For more examples see <a href="https://github.com/gammasoft71/Switch/tree/master/Examples">Examples</a>.
///
/// @section DownloadSection Download Switch
///
/// Before running examples you must download and install Switch. To download and install it read <a href="https://gammasoft71.wixsite.com/switch/downloads">Downloads</a> page or <a href="https://github.com/gammasoft71/Switch/tree/master/docs/Downloads.md">Downloads.md</a> file.
