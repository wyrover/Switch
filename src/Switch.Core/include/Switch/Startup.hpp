/// @file
/// @brief Contains #_startup keyword.
#pragma once

#include "System/Delegate.hpp"
#include "System/Environment.hpp"

namespace Switch {
  /// @brief Defines the entry point to be called when the application loads. Generally this is set either to the main form in your application or to the Main procedure that should run when the application starts.
  /// @param mainClass The class that contains the static Main method.
  /// @par Examples
  /// This example show a Main method without arguments and without return code
  /// @include Main1.cpp
  /// @par
  /// This example show a Main method with a return code without arguments
  /// @include Main2.cpp
  /// @par
  /// This example show a Main method with argument and without return code
  /// @include Main3.cpp
  /// @par
  /// This example show a Main method with argument and return code
  /// @include Main4.cpp
  /// @ingroup Keywords
  #define _startup(mainClass) \
  int main(int argc, char* argv[]) {\
    struct Startup {\
      int operator()(System::Delegate<void>::FunctionPointer startup, const System::Array<System::String>& args) {startup(); return System::Environment::ExitCode;}\
      int operator()(System::Delegate<int>::FunctionPointer startup, const System::Array<System::String>& args) {return startup();}\
      int operator()(System::Delegate<void, const System::Array<System::String>&>::FunctionPointer startup, const System::Array<System::String>& args) {startup(args); return System::Environment::ExitCode;}\
      int operator()(System::Delegate<int, const System::Array<System::String>&>::FunctionPointer startup, const System::Array<System::String>& args) {return startup(args);}\
    };\
    return Startup()(mainClass::Main, System::Environment::SetCommandLineArgs(argv, argc));\
  } \
  int __unused_main_argc__
}
