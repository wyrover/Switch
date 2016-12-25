/// @page TutorialHelloWorldPage Hello World
///
/// This tutorial shows several versions of a Hello World program in Pcf c++.
///
/// @section TutorialSection Tutorial
/// The following examples show different ways of writing the C++ Hello World program.
///
/// @section Example1Section Example 1
/// @code
/// //Hello1.cpp
/// #include <Pcf/Pcf>
///
/// class Hello1 {
/// public:
///   static void Main() {
///     System::Console::WriteLine("Hello, World!");
///   }
/// };
///
/// pcf_startup(Hello1)
/// @endcode
/// @b Output
/// @verbatim Hello, world! @endverbatim
///
/// Code Discussion
/// Every Main method must be contained inside a class (Hello1 in this case).
/// The System::Console class contains a WriteLine method that can be used to display a string to the console.
///
/// @section Example2Section Example 2
///
/// To avoid fully qualifying classes throughout a program, you can use the using directive as shown below:
/// @code
/// //Hello2.cpp
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class Hello2 {
/// public:
///   static void Main() {
///     Console::WriteLine("Hello, World!");
///   }
/// };
///
/// pcf_startup(Hello2)
/// @endcode
/// @b Output
/// @verbatim Hello, world! @endverbatim
///
/// @section Example3Section Example 3
///
/// If you need access to the command line parameters passed in to your application, simply change the signature of the Main method to include them as shown below. This example counts and displays the command line arguments.
/// @code
/// // Hello3.cpp
/// // arguments: A B C D
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class Hello3 {
/// public:
///   static void Main(const Array<string>& args) {
///     Console::WriteLine("Hello, World!");
///     Console::WriteLine("You entered the following {0} command line arguments:", args.Length);
///     for (int i=0; i < args.Length; i++) {
///       Console::WriteLine("{0}", args[i]);
///     }
///   }
/// };
///
/// pcf_startup(Hello3)
/// @endcode
/// @b Output
/// @verbatim Hello, world!
 You entered the following 4 command line arguments:
 A
 B
 C
 D @endverbatim
///
/// @section Example4Section Example 4
///
/// To return a return code, change the signature of the Main method as shown below:
/// @code
/// // Hello4.cpp
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class Hello4 {
/// public:
///   static int Main() {
///     Console::WriteLine("Hello, World!");
///     return 0;
///   }
/// };
///
/// pcf_startup(Hello4)
/// @endcode
/// @b Output
/// @verbatim Hello, world! @endverbatim
