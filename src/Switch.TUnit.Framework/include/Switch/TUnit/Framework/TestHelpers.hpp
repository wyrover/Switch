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

#undef IgnoreTest_
#undef SetUp_
#undef TearDown_
#undef Test_
#undef TestFixture_
#undef AddTest_
#undef AddTestFixture_

#define AddTest_(className, methodName)

#define AddTestFixture_(className) \
  TUnit::Framework::TestFixtureAttribute<className> __##className##Attribute {#className}

#define _OneTimeSetUp(methodName) \
  __##methodName##_unused() {} \
  struct methodName##Attribute : public TUnit::Framework::OneTimeSetUpAttribute { \
    template<typename TestFixture> methodName##Attribute(TestFixture& test) : OneTimeSetUpAttribute(#methodName, test, &TestFixture::methodName, caller_) {} \
  } __##methodName##Attribute {*this}; \
  void methodName()

#define _OneTimeTearDown(methodName) \
  __##methodName##_unused() {} \
  struct methodName##Attribute : public TUnit::Framework::OneTimeTearDownAttribute { \
    template<typename TestFixture> methodName##Attribute(TestFixture& test) : OneTimeTearDownAttribute(#methodName, test, &TestFixture::methodName, caller_) {} \
  } __##methodName##Attribute {*this}; \
  void methodName()

#define SetUp_(methodName) \
  __##methodName##_unused() {} \
  struct methodName##Attribute : public TUnit::Framework::SetUpAttribute { \
    template<typename TestFixture> methodName##Attribute(TestFixture& test) : SetUpAttribute(#methodName, test, &TestFixture::methodName, caller_) {} \
  } __##methodName##Attribute {*this}; \
  void methodName()

#define TearDown_(methodName) \
  __##methodName##_unused() {} \
  struct methodName##Attribute : public TUnit::Framework::TearDownAttribute { \
    template<typename TestFixture> methodName##Attribute(TestFixture& test) : TearDownAttribute(#methodName, test, &TestFixture::methodName, caller_) {} \
  } __##methodName##Attribute {*this}; \
  void methodName()

#define TestFixture_(className) \
  className : public TUnit::Framework::TestFixture

#define Test_(methodName) \
  __##methodName##_unused() {} \
  struct methodName##Attribute : public TUnit::Framework::TestAttribute { \
    template<typename TestFixture> methodName##Attribute(TestFixture& test) : TestAttribute(#methodName, test, &TestFixture::methodName, caller_) {} \
  } __##methodName##Attribute {*this}; \
  void methodName()

#define IgnoreTest_(methodName) \
  __##methodName##_unused() {} \
  struct methodName##Attribute : public TUnit::Framework::TestAttribute { \
    template<typename TestFixture> methodName##Attribute(TestFixture& test) : TestAttribute(#methodName, test, &TestFixture::methodName, TUnit::Framework::TestState::Ignored, caller_) {} \
  } __##methodName##Attribute {*this}; \
  void methodName()

