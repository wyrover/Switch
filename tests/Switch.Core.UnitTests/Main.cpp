#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

namespace testing {
  namespace internal {
    AssertionResult CmpHelperEQ(const char* expectedExpression, const char* actualExpression, char expected, const char32& actual) {return CmpHelperEQ(expectedExpression, actualExpression, expected, (char)actual);}
    AssertionResult CmpHelperEQ(const char* expectedExpression, const char* actualExpression, int expected, const char32& actual) {return CmpHelperEQ(expectedExpression, actualExpression, expected, (int)actual);}
  }
}

int main(int argc, char* argv[]) {
  System::Exception::StackTraceEnabled(false);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
