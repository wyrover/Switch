/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct TearDownAttribute {
        template<typename TestFixture>
        TearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  TearDownAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        TearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddTearDown({name, {testFixture, method}, caller});}
      };
    }
  }
}

using namespace Switch;
