/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct SetUpAttribute {
        template<typename TestFixture>
        SetUpAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  SetUpAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        SetUpAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddSetUp({name, {testFixture, method}, caller});}
      };
    }
  }
}

using namespace Switch;
