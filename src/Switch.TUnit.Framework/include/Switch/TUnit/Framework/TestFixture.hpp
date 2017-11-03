/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "RegisteredMethod.hpp"

namespace Switch {
  namespace TUnit {
    namespace Framework {
      struct TestFixture : public object {
        void AddOneTimeSetUp(const RegisteredMethod& registeredMethod) {this->oneTimeSetUps.Add(registeredMethod);}
        void AddOneTimeTearDown(const RegisteredMethod& registeredMethod) {this->oneTimeTearDowns.Add(registeredMethod);}
        void AddSetUp(const RegisteredMethod& registeredMethod) {this->setUps.Add(registeredMethod);}
        void AddTearDown(const RegisteredMethod& registeredMethod) {this->tearDowns.Add(registeredMethod);}
        void AddTest(const RegisteredMethod& registeredMethod) {this->tests.Add(registeredMethod);}

      protected:
        friend class UnitTest;
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
methodName##_one_time_set_up_unused_method() {} \
struct methodName##_one_time_set_up { \
  methodName##_one_time_set_up(Test_fixture_type* test) {test->AddOneTimeSetUp({#methodName, {*test, &Test_fixture_type::methodName}, _caller});} \
} methodName##_one_time_set_up_value {this}; \
void methodName

#define _one_time_tear_down(methodName) \
methodName##_one_time_tear_down_unused_method() {} \
struct methodName##_one_time_tear_down { \
  methodName##_one_time_tear_down(Test_fixture_type* test) {test->AddOneTimeTearDown({#methodName, {*test, &Test_fixture_type::methodName}, _caller});} \
} methodName##_one_time_tear_down_value {this}; \
void methodName

#define _set_up(methodName) \
methodName##_setup_unused_method() {} \
struct methodName##_setup { \
  methodName##_setup(Test_fixture_type* test) {test->AddSetUp({#methodName, {*test, &Test_fixture_type::methodName}, _caller});} \
} methodName##_setup_value {this}; \
void methodName

#define _tear_down(methodName) \
methodName##_teardown_unused_method() {} \
struct methodName##_teardown { \
  methodName##_teardown(Test_fixture_type* test) {test->AddTearDown({#methodName, {*test, &Test_fixture_type::methodName}, _caller});} \
} methodName##_teardown_value {this}; \
void methodName

#define _test_fixture(className) \
className; \
using Test_fixture_type = className; \
class className : public TUnit::Framework::TestFixture

#define _test(methodName) \
methodName##_test_unused_method() {} \
struct methodName##_test { \
  methodName##_test(Test_fixture_type* test) {test->AddTest({#methodName, {*test, &Test_fixture_type::methodName}, _caller});} \
} methodName##_test_value {this}; \
void methodName

#define _ignore_test(methodName) \
methodName##_test_unused_method() {} \
struct methodName##_test { \
  methodName##_test(Test_fixture_type* test) {test->AddTest({#methodName, {*test, &Test_fixture_type::methodName}, true, _caller});} \
} methodName##_test_value {this}; \
void methodName

#define _add_test_fixture(className) \
static struct className##_test_fixture { \
  className##_test_fixture() {TUnit::Framework::UnitTest::Add({#className, ref_new<className>()});} \
} className##_test_fixture_value;

#define _add_test(className, methodName)

#define _test_class_initialize(methodName) _one_time_set_up(methodName)

#define _test_class_cleanup(methodName) _one_time_tear_down((methodName)

#define _test_initialize(methodName) _set_up(methodName)

#define _test_cleanup(methodName) _tear_down((methodName)

#define _test_class(className) _test_fixture(className)

#define _test_method(methodName) _test(methodName)

#define _ignore_test_method(methodName) _ignore_test(methodName)

#define _add_test_class(className) _add_test_fixture(className)

