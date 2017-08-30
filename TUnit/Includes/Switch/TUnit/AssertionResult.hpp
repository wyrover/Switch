/// @file
/// @brief Contains Switch::TUnit::AssertionResult class.
#pragma once

#include <cstring>
#include <iostream>

#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>

/// @cond
namespace testing {
  class AssertionResult;
  namespace internal {
    AssertionResult CmpHelperEQ(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual);
    AssertionResult CmpHelperNE(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual);
    AssertionResult CmpHelperLE(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual);
    AssertionResult CmpHelperLT(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual);
    AssertionResult CmpHelperGE(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual);
    AssertionResult CmpHelperGT(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual);
    AssertionResult CmpHelperEQ(const char* expectedExpression, const char* actualExpression, char expected, const char32& actual);
    AssertionResult CmpHelperEQ(const char* expectedExpression, const char* actualExpression, int expected, const char32& actual);
    AssertionResult CmpHelperEQ(const char* expectedExpression, const char* actualExpression, const System::String& expected, const System::String& actual);
    AssertionResult CmpHelperNE(const char* expectedExpression, const char* actualExpression, const System::String& expected, const System::String& actual);
  }
}

#include <gtest/gtest.h>

::testing::AssertionResult AssertObjectEqStr(const char* expectedExpression,const char* actualExpression,const System::String& expected,const char* actual);
::testing::AssertionResult AssertObjectEqStr(const char* expectedExpression,const char* actualExpression,const char* expected,const System::String& actual);

/// @endcond
