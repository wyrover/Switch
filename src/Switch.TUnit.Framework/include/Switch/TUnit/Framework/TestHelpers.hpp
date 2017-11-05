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

#undef _IgnoreTest
#undef _SetUp
#undef _TearDown
#undef _Test
#undef _TestFixture
#undef _AddTest
#undef _AddTestFixture

#define _AddTest(className, methodName)

#define _AddTestFixture(className) \
TUnit::Framework::TestFixtureAttribute<className> __##className##Attribute {#className};

#define _OneTimeSetUp(methodName) \
__##methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::OneTimeSetUpAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : OneTimeSetUpAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _OneTimeTearDown(methodName) \
__##methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::OneTimeTearDownAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : OneTimeTearDownAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _SetUp(methodName) \
__##methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::SetUpAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : SetUpAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _TearDown(methodName) \
__##methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::TearDownAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : TearDownAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _TestFixture(className) \
className : public TUnit::Framework::TestFixture

#define _Test(methodName) \
__##methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::TestAttribute { \
  template<typename TestFixture> methodName##Attribute(TestFixture& test) : TestAttribute(#methodName, test, &TestFixture::methodName, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

#define _IgnoreTest(methodName) \
__##methodName##_unused() {} \
struct methodName##Attribute : public TUnit::Framework::TestAttribute { \
template<typename TestFixture> methodName##Attribute(TestFixture& test) : TestAttribute(#methodName, test, &TestFixture::methodName, TUnit::Framework::TestState::Ignored, _caller) {} \
} __##methodName##Attribute {*this}; \
void methodName()

