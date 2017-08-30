/// @file
/// @brief Contains Switch::TUnit::UnitTest class.
#pragma once

#include <Switch/System/Array.hpp>
#include <Switch/System/String.hpp>

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @remarks This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @remarks This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    class UnitTest {
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
