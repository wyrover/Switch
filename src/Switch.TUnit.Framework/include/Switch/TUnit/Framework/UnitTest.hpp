/// @file
/// @brief Contains include files of TUnit::Framework::RegisteredMethod struct.
#pragma once

#include "RegisteredTestFixture.hpp"
#include <Switch/System/Array.hpp>

namespace Switch {
  namespace TUnit {
    namespace Framework {
      /// @brief UnitTest is...
      class UnitTest {
      public:
        UnitTest() {}
        
        UnitTest(const System::Array<string>& args) {
          this->alsoRunIgnoredTests = true;
        }
        
        int32 Run() {
          for(auto registeredTestFixture : RegisteredTestFixtures()) {
            this->OneTimeSetUp(registeredTestFixture);
            for(auto test : registeredTestFixture.testFixture->tests) {
              if(!test.ignore || this->alsoRunIgnoredTests) {
                this->SetUp(registeredTestFixture);
                test.method();
                this->TearDown(registeredTestFixture);
              }
            }
            this->OneTimeTearDown(registeredTestFixture);
          }
          return 0;
        }
        
      private:
        template <typename TestFixture>
        friend struct TestFixtureAttribute;
        
        static void Add(const RegisteredTestFixture& registeredTestFixture) {RegisteredTestFixtures().Add(registeredTestFixture);}
        
        void OneTimeSetUp(const RegisteredTestFixture& registeredTestFixture) {
          for(auto oneTimeSetUp : registeredTestFixture.testFixture->oneTimeSetUps)
            oneTimeSetUp.method();
        }
        
        void OneTimeTearDown(const RegisteredTestFixture& registeredTestFixture) {
          for(auto oneTimeTearDown : registeredTestFixture.testFixture->oneTimeTearDowns)
            oneTimeTearDown.method();
        }
        
        void SetUp(const RegisteredTestFixture& registeredTestFixture) {
          for(auto setup : registeredTestFixture.testFixture->setUps)
            setup.method();
        }
        
        void TearDown(const RegisteredTestFixture& registeredTestFixture) {
          for(auto tearDown : registeredTestFixture.testFixture->tearDowns)
            tearDown.method();
        }
        
        static System::Collections::Generic::List<TUnit::Framework::RegisteredTestFixture>& RegisteredTestFixtures() {
          static System::Collections::Generic::List<TUnit::Framework::RegisteredTestFixture> registeredTestFixtures;
          return registeredTestFixtures;
        }
        
        bool alsoRunIgnoredTests = false;
      };
    }
  }
}

using namespace Switch;
