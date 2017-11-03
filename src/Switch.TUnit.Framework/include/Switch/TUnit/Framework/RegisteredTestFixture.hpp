/// @file
/// @brief Contains include files of TUnit::Framework::RegisteredMethod struct.
#pragma once

#include "TestFixture.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct RegisteredTestFixture : public object {
        RegisteredTestFixture(const string& name, refptr<TUnit::Framework::TestFixture> testFixture) : name(name), testFixture(testFixture) {}
        
      private:
        friend class UnitTest;
        string name;
        refptr<TestFixture> testFixture;
      };
    }
  }
}

using namespace Switch;
