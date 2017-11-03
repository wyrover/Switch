/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct OneTimeTearDownAttribute {
        template<typename TestFixture>
        OneTimeTearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  OneTimeTearDownAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        OneTimeTearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddOneTimeTearDown({name, {testFixture, method}, caller});}
      };
    }
  }
}

using namespace Switch;
