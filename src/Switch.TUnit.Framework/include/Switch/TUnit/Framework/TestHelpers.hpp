/// @file
/// @brief Contains include files of TUnit library.
#pragma once

#include "OneTimeSetUpAttribute.hpp"
#include "OneTimeTearDownAttribute.hpp"
#include "SetUpAttribute.hpp"
#include "TearDownAttribute.hpp"
#include "TestAttribute.hpp"
#include "TestFixture.hpp"
#include "TestFixtureAttribute.hpp"

#undef _ignore_test
#undef _set_up
#undef _tear_down
#undef _test
#undef _test_fixture
#undef _add_test
#undef _add_test_fixture

#define _add_test_fixture(className) \
TUnit::Framework::TestFixtureAttribute<className> __##className##Attribute {#className};

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

#define _add_test_class(className) _add_test_fixture(className)

#define _add_test(className, methodName)

#define _test_class_initialize(methodName) _one_time_set_up(methodName)

#define _test_class_cleanup(methodName) _one_time_tear_down(methodName)

#define _test_initialize(methodName) _set_up(methodName)

#define _test_cleanup(methodName) _tear_down(methodName)

#define _test_class(className) _test_fixture(className)

#define _test_method(methodName) _test(methodName)

#define _ignore_test_method(methodName) _ignore_test(methodName)
