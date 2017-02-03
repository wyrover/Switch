/// @page TutorialCommandLineParametersPage Command Line Parameters
///
/// This tutorial shows how the command line can be accessed and two ways of accessing the array of command line parameters.
///
/// @section TutorialSection Tutorial
/// The following examples show two different approaches to using the command line arguments passed to an application.
///
/// @section Example1Section Example 1
///
/// This example demonstrates how to print out the command line arguments.
/// @code
/// // cmdline1.cpp
/// // arguments: A B C
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class CommandLine {
/// public:
///   static void Main(const Array<string>& args) {
///     // The Length property is used to obtain the length of the array.
///     // Notice that Length is a read-only property:
///     Console::WriteLine("Number of command line parameters = {0}", args.Length);
///     for(int i = 0; i < args.Length; i++) {
///       Console::WriteLine("Arg[{0}] = [{1}]", i, args[i]);
///     }
///   }
/// };
///
/// pcf_startup(CommandLine)
/// @endcode
/// @b Output
/// Run the program using some arguments like this: cmdline1 A B C.
/// @verbatim Number of command line parameters = 3
 Arg[0] = [A]
 Arg[1] = [B]
 Arg[2] = [C]@endverbatim
///
/// @section Example2Section Example 2
///
/// Another approach to iterating over the array is to use the foreach statement as shown in this example. The foreach statement can be used to iterate over an array or over a Pcf Framework collection class. It provides a simple way to iterate over collections.
/// @code
/// // cmdline2.cpp
/// // arguments: John Paul Mary
/// #include <Pcf/Pcf>
///
/// using namespace System;
///
/// class CommandLine2 {
/// public:
///   static void Main(const System::Array<string>& args) {
///     // The Length property is used to obtain the length of the array.
///     // Notice that Length is a read-only property:
///     Console::WriteLine("Number of command line parameters = {0}", args.Length);
///     foreach (String s, args) {
///       Console::WriteLine(s);
///     }
///   }
/// };
///
/// pcf_startup(CommandLine2)
/// @endcode
/// @b Output
/// Run the program using some arguments like this: cmdline2 John Paul Mary.
///
/// The output will be:
/// @verbatim Number of command line parameters = 3
 John
 Paul
 Mary @endverbatim
