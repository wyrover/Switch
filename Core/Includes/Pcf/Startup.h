/// @file
/// @brief Contains #pcf_startup keyword.
#pragma once

#include "System/Environment.h"

namespace Pcf {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the Main procedure that should run when the application starts.
  /// @param mainClass The class that contains the static Main method.
  /// @par Examples
  /// This example show a Main method without arguments and without return code
  /// @code
  /// #include <Pcf/Pcf>
  ///
  /// class Hello1 {
  /// public:
  ///   static void Main() {
  ///     System::Console::WriteLine("Hello, World!");
  ///   }
  /// };
  ///
  /// pcf_startup (Hello1);
  /// @endcode
  /// @par
  /// This example show a Main method with a return code without arguments
  /// @code
  /// #include <Pcf/Pcf>
  /// 
  /// class Hello2 {
  /// public:
  ///   static int Main() {
  ///     System::Console::WriteLine("Hello, World!");
  ///     return 42;
  ///   }
  /// };
  ///
  /// pcf_startup (Hello2);
  /// @endcode
  /// @par
  /// This example show a Main method with argument and without return code
  /// @code
  /// #include <Pcf/Pcf>
  /// 
  /// class Arguments1 {
  /// public:
  ///   static void Main(const Array<System::String>& args) {
  ///     for (System::String arg : args)
  ///       System::Console::WriteLine(arg);
  ///   }
  /// };
  ///
  /// pcf_startup (Arguments1);
  /// @endcode
  /// @par
  /// This example show a Main method with argument and return code
  /// @code
  /// #include <Pcf/Pcf>
  /// 
  /// class Arguments2 {
  /// public:
  ///   static int Main(const Array<System::String>& args) {
  ///     for (System::String arg : args)
  ///       System::Console::WriteLine(arg);
  ///     return 42;
  ///   }
  /// };
  ///
  /// pcf_startup (Arguments2);
  /// @endcode
  /// @ingroup Pcf
  #define pcf_startup(mainClass)\
  int main(int argc, char* argv[]) {\
    struct Startup {\
      int operator()(void(*startup)(), const System::Array<System::String>& args) {startup(); return System::Environment::ExitCode;}\
      int operator()(int(*startup)(), const System::Array<System::String>& args) {return startup();}\
      int operator()(void(*startup)(const System::Array<System::String>&), const System::Array<System::String>& args) {startup(args); return System::Environment::ExitCode;}\
      int operator()(int(*startup)(const System::Array<System::String>&), const System::Array<System::String>& args) {return startup(args);}\
    };\
    return Startup()(mainClass::Main, System::Environment::SetCommandLineArgs(argv, argc));\
  }
}
