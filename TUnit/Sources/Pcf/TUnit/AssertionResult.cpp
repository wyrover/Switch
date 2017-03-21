#include <Pcf/System/Array.h>
#include "../../../Includes/Pcf/TUnit/AssertionResult.h"

using namespace System;

// The helper function for {ASSERT|EXPECT}_EQ with System::String.
testing::AssertionResult testing::internal::CmpHelperEQ(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual) {
  std::string exp(expected);
  std::string act(actual.ToCCharArray().Data());
  
  if (actual == expected)
    return testing::AssertionSuccess();
  
  return testing::internal::EqFailure(expectedExpression, actualExpression, FormatForComparisonFailureMessage(exp, act), FormatForComparisonFailureMessage(act, exp), false);
}

// The helper function for {ASSERT|EXPECT}_EQ with System::String.
testing::AssertionResult testing::internal::CmpHelperEQ(const char* expectedExpression, const char* actualExpression, const System::String& expected, const System::String& actual) {
  std::string exp(expected.ToCCharArray().Data());
  std::string act(actual.ToCCharArray().Data());

  if (actual == expected)
    return testing::AssertionSuccess();

  return testing::internal::EqFailure(expectedExpression, actualExpression, FormatForComparisonFailureMessage(exp, act), FormatForComparisonFailureMessage(act, exp), false);
}

testing::AssertionResult testing::internal::CmpHelperEQ(const char* expectedExpression, const char* actualExpression, char expected, const char32& actual) {  
  if (actual == static_cast<char32>(expected))
    return testing::AssertionSuccess();

  std::string exp, act;
  exp.push_back(expected);
  if (static_cast<int32>(actual) < 128) {
    act.push_back(static_cast<char>(actual));
  } else {
    std::stringstream ss;
    ss << "\\u" << std::hex << static_cast<int32>(actual);
  }
  
  return testing::internal::EqFailure(expectedExpression, actualExpression, FormatForComparisonFailureMessage(exp, act), FormatForComparisonFailureMessage(act, exp), false);
}

testing::AssertionResult testing::internal::CmpHelperEQ(const char* expectedExpression, const char* actualExpression, int expected, const char32& actual) {  
  if (actual == static_cast<char32>(expected))
    return testing::AssertionSuccess();

  std::string exp, act;
  
  if (expected < 128) {
    exp.push_back(static_cast<char>(actual));
  } else {
    std::stringstream ss;
    ss << "\\u" << std::hex << expected;
  }

  if (static_cast<int32>(actual) < 128) {
    act.push_back(static_cast<char>(actual));
  } else {
    std::stringstream ss;
    ss << "\\u" << std::hex << static_cast<int32>(actual);
  }
  
  return testing::internal::EqFailure(expectedExpression, actualExpression, 
    FormatForComparisonFailureMessage(exp, act), FormatForComparisonFailureMessage(act, exp), false);
}

// The helper function for {ASSERT|EXPECT}_NE with System::String.
testing::AssertionResult testing::internal::CmpHelperNE(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual) {  
  if (actual != expected)
    return testing::AssertionSuccess();
  
  return AssertionFailure() << "Expected: (" << expectedExpression << ") != (" << actualExpression << "), actual: \"" << expected << "\" vs \"" << actual << "\"";
}

// The helper function for {ASSERT|EXPECT}_NE with System::String.
testing::AssertionResult testing::internal::CmpHelperNE(const char* expectedExpression, const char* actualExpression, const System::String& expected, const System::String& actual) {
  if (actual != expected)
    return testing::AssertionSuccess();

  return AssertionFailure() << "Expected: (" << expectedExpression << ") != (" << actualExpression << "), actual: \"" << expected << "\" vs \"" << actual << "\"";
}

// The helper function for {ASSERT|EXPECT}_LE with System::String.
testing::AssertionResult testing::internal::CmpHelperLE(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual) {
  if (actual >= expected)
    return testing::AssertionSuccess();
  
  return AssertionFailure() << "Expected: (" << expectedExpression << ") <= (" << actualExpression << "), actual: \"" << expected << "\" vs \"" << actual << "\"";
}

// The helper function for {ASSERT|EXPECT}_LT with System::String.
testing::AssertionResult testing::internal::CmpHelperLT(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual) {
  if (actual > expected)
    return testing::AssertionSuccess();
  
  return AssertionFailure() << "Expected: (" << expectedExpression << ") < (" << actualExpression << "), actual: \"" << expected << "\" vs \"" << actual << "\"";
}

// The helper function for {ASSERT|EXPECT}_GE with System::String.
testing::AssertionResult testing::internal::CmpHelperGE(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual) {
  if (actual <= expected)
    return testing::AssertionSuccess();
  
  return AssertionFailure() << "Expected: (" << expectedExpression << ") >= (" << actualExpression << "), actual: \"" << expected << "\" vs \"" << actual << "\"";
}

// The helper function for {ASSERT|EXPECT}_GT with System::String.
testing::AssertionResult testing::internal::CmpHelperGT(const char* expectedExpression, const char* actualExpression, const char* expected, const System::String& actual) {
  if (actual < expected)
    return testing::AssertionSuccess();
  
  return AssertionFailure() << "Expected: (" << expectedExpression << ") > (" << actualExpression << "), actual: \"" << expected << "\" vs \"" << actual << "\"";
}

::testing::AssertionResult AssertObjectEqStr(const char* expectedExpression,const char* actualExpression,const String& expected,const char* actual) {
  if (expected.Equals(String(actual)))
    return testing::AssertionSuccess();
  
  ::testing::AssertionResult ret = ::testing::AssertionFailure() << expectedExpression << "\n     is : " << expected.ToCCharArray().Data() << "\nand not : " << actual << "\nas expected";
  return ret;
}

::testing::AssertionResult AssertObjectEqStr(const char* expectedExpression,const char* actualExpression,const char* expected,const String& actual) {
  if (actual.Equals(String(expected)))
    return testing::AssertionSuccess();
  
  ::testing::AssertionResult ret = ::testing::AssertionFailure() << expectedExpression << "\n     is : " << expected << "\nand not : " << actual.ToCCharArray().Data() << "\nas expected";
  return ret;
}
