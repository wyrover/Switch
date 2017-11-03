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
      
      struct OneTimeTearDownAttribute {
        template<typename TestFixture>
        OneTimeTearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  OneTimeTearDownAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        OneTimeTearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddOneTimeTearDown({name, {testFixture, method}, caller});}
      };

      struct SetUpAttribute {
        template<typename TestFixture>
        SetUpAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  SetUpAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        SetUpAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddSetUp({name, {testFixture, method}, caller});}
      };
      
      struct TearDownAttribute {
        template<typename TestFixture>
        TearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)()) :  TearDownAttribute(name, testFixture, method, System::Runtime::CompilerServices::Caller()) {}
        template<typename TestFixture>
        TearDownAttribute(const string& name, TestFixture& testFixture, void (TestFixture::*method)(), const System::Runtime::CompilerServices::Caller& caller) {testFixture.AddTearDown({name, {testFixture, method}, caller});}
      };
      
      enum class TestState {
        Considered,
        Ignored
      };
      
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

      struct TestFixture : public object {
      protected:
        void AddOneTimeTearDown(const RegisteredMethod& registeredMethod) {this->oneTimeTearDowns.Add(registeredMethod);}
        void AddSetUp(const RegisteredMethod& registeredMethod) {this->setUps.Add(registeredMethod);}
        void AddTearDown(const RegisteredMethod& registeredMethod) {this->tearDowns.Add(registeredMethod);}
        void AddTest(const RegisteredMethod& registeredMethod) {this->tests.Add(registeredMethod);}

      private:
        friend class UnitTest;
        friend struct OneTimeSetUpAttribute;
        friend struct OneTimeTearDownAttribute;
        friend struct SetUpAttribute;
        friend struct TearDownAttribute;
        friend struct TestAttribute;

        void AddOneTimeSetUp(const RegisteredMethod& registeredMethod) {this->oneTimeSetUps.Add(registeredMethod);}
        
        System::Collections::Generic::List<RegisteredMethod> oneTimeSetUps;
        System::Collections::Generic::List<RegisteredMethod> oneTimeTearDowns;
        System::Collections::Generic::List<RegisteredMethod> setUps;
        System::Collections::Generic::List<RegisteredMethod> tearDowns;
        System::Collections::Generic::List<RegisteredMethod> tests;
      };
    }
  }
}

#undef _ignore_test
#undef _set_up
#undef _tear_down
#undef _test
#undef _test_fixture
#undef _add_test
#undef _add_test_fixture

#define _one_time_set_up(methodName) \
methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::OneTimeSetUpAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : OneTimeSetUpAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _one_time_tear_down(methodName) \
methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::OneTimeTearDownAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : OneTimeTearDownAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _set_up(methodName) \
methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::SetUpAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : SetUpAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _tear_down(methodName) \
methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::TearDownAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : TearDownAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _test_fixture(className) \
className : public TUnit::Framework::TestFixture

#define _test(methodName) \
methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::TestAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : TestAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _ignore_test(methodName) \
methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::TestAttribute { \
template<typename TestFixture> methodName##Attribute(TestFixture& test) : TestAttribute(#methodName, test, &TestFixture::methodName, TUnit::Framework::TestState::Ignored, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _add_test(className, methodName)

#define _test_class_initialize(methodName) _one_time_set_up(methodName)

#define _test_class_cleanup(methodName) _one_time_tear_down(methodName)

#define _test_initialize(methodName) _set_up(methodName)

#define _test_cleanup(methodName) _tear_down(methodName)

#define _test_class(className) _test_fixture(className)

#define _test_method(methodName) _test(methodName)

#define _ignore_test_method(methodName) _ignore_test(methodName)
