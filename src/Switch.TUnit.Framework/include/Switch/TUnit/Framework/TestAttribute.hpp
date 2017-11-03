/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"
#include "TestState.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct TestAttribute {
        template<typename TestFixture>
        TestAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) : TestAttribute(name, testFixture, method, TestState::Considered, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        TestAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) : TestAttribute(name, testFixture, method, TestState::Considered, _caller) {}
        template<typename TestFixture>
        TestAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), TestState testState)  : TestAttribute(name, testFixture, method, testState, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        TestAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), TestState testState, const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddTest({name, {testFixture, method}, testState == TestState::Ignored, caller});}
      };
    }
  }
}

using namespace Switch;
