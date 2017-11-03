/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct OneTimeSetUpAttribute {
        template<typename TestFixture>
        OneTimeSetUpAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  OneTimeSetUpAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        OneTimeSetUpAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddOneTimeSetUp({name, {testFixture, method}, caller});}
      };
    }
  }
}

using namespace Switch;
