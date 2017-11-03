/// @file
/// @brief Contains include files of TUnit::Framework::RegisteredMethod struct.
#pragma once
#define TRACE

#include "RegisteredTestFixture.hpp"
#include <Switch/System/Diagnostics/Trace.hpp>
#include <Switch/System/Array.hpp>

namespace Switch {
  namespace TUnit {
    namespace Framework {
      /// @brief UnitTest is...
      class UnitTest {
      public:
        UnitTest(const System::Array<string>& args) {
          this->alsoRunIgnoredTests = true;
        }
        void Run() {
          for(auto registeredTestFixture : RegisteredTestFixtures()) {
            this->OneTimeSetUp(registeredTestFixture);
            for (auto test : registeredTestFixture.testFixture->tests) {
              if (!test.ignore || this->alsoRunIgnoredTests) {
                this->SetUp(registeredTestFixture);
                System::Diagnostics::Trace::WriteLine(string::Format("call {0}", ToString(registeredTestFixture, test)));
                test.method();
                this->TearDown(registeredTestFixture);
              }
            }
            this->OneTimeTearDown(registeredTestFixture);
          }
        }
        
        static void Add(const RegisteredTestFixture& registeredTestFixture) {RegisteredTestFixtures().Add(registeredTestFixture);}
 
      private:
        string ToString(const RegisteredTestFixture& registeredTestFixture, const RegisteredMethod& registeredMethod) {
          return string::Format("{0}{1}::{2}", registeredMethod.ignore ? "ignored " : "" , registeredTestFixture.name, registeredMethod.name);
        }
        
        void OneTimeSetUp(const RegisteredTestFixture& registeredTestFixture) {
          for (auto oneTimeSetUp : registeredTestFixture.testFixture->oneTimeSetUps) {
            System::Diagnostics::Trace::WriteLine(string::Format("call {0}", ToString(registeredTestFixture, oneTimeSetUp)));
            oneTimeSetUp.method();
          }
        }
        
        void OneTimeTearDown(const RegisteredTestFixture& registeredTestFixture) {
          for (auto oneTimeTearDown : registeredTestFixture.testFixture->oneTimeTearDowns) {
            System::Diagnostics::Trace::WriteLine(string::Format("call {0}", ToString(registeredTestFixture, oneTimeTearDown)));
            oneTimeTearDown.method();
          }
        }
        
        void SetUp(const RegisteredTestFixture& registeredTestFixture) {
          for (auto setup : registeredTestFixture.testFixture->setUps) {
            System::Diagnostics::Trace::WriteLine(string::Format("call {0}", ToString(registeredTestFixture, setup)));
            setup.method();
          }
        }
        
        void TearDown(const RegisteredTestFixture& registeredTestFixture) {
          for (auto tearDown : registeredTestFixture.testFixture->tearDowns) {
            System::Diagnostics::Trace::WriteLine(string::Format("call {0}", ToString(registeredTestFixture, tearDown)));
            tearDown.method();
          }
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

