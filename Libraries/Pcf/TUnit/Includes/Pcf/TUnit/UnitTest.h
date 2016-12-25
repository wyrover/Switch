/// @file
/// @brief Contains Pcf::TUnit::UnitTest class.
#pragma once

#include "ConsoleEventListener.h"
#include <Pcf/System/Array.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Environment.h>
#include <Pcf/System/String.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @remarks This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @remarks This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    class UnitTest {
    public:
      UnitTest(char* argv[], int argc) : UnitTest(System::Environment::SetCommandLineArgs(argv, argc)) {}
      
      UnitTest(const System::Array<System::String>& args) {Init(args);}
      
      int32 Run();
      
    private:
      void Init(const System::Array<System::String>& args);
      System::Array<System::String> ConvertParam(const System::Array<System::String>& args);

      System::Array<System::String> args;
    };
  }
}

using namespace Pcf;

