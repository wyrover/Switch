/// @file
/// @brief Contains Switch::TUnit::UnitTest class.
#pragma once

#include <Switch/Export.hpp>
#include <Switch/System/Array.hpp>
#include <Switch/System/String.hpp>
#include "../TUnitCoreExport.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @remarks This example how to use TestFixture class, Assert class and #AddTest_ method:
  /// @include Assert.cpp
  /// @remarks This example how to use TestFixture class, Expect class and #AddTest_ method:
  /// @include Expect.cpp
  namespace TUnit {
    class tunit_core_export_ UnitTest {
    public:
      UnitTest(const System::Array<System::String>& args);

      int32 Run();

    private:
      System::Array<System::String> ConvertParam(const System::Array<System::String>& args);

      System::Array<System::String> args;
    };
  }
}

using namespace Switch;
