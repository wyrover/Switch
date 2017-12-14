#include <Switch/ExceptionPtr.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(ExceptionPointerTest, CreateExceptionPointerEmptyThenRethrow) {
    ExceptionPtr ep;
    ASSERT_TRUE(ep == null);
    ASSERT_NO_THROW(ep.Rethrow());
  }

  TEST(ExceptionPointerTest, CreateKnownExceptionThenRethrow) {
    ExceptionPtr ep = ExceptionPtr::Create(InvalidCastException());
    ASSERT_FALSE(ep == null);
    ASSERT_THROW(ep.Rethrow(), InvalidCastException);
  }

  TEST(ExceptionPointerTest, CreateUnknownExceptionThenRethrow) {
    struct MyException {};
    ExceptionPtr ep = ExceptionPtr::Create(MyException());
    ASSERT_FALSE(ep == null);
    ASSERT_THROW(ep.Rethrow(), MyException);
  }

  TEST(ExceptionPointerTest, GetCurrentExceptionOnNullExceptionThenRethrow) {
    ExceptionPtr ep;
    {
      ep = ExceptionPtr::CurrentException();
    }
    ASSERT_TRUE(ep == null);
    ASSERT_NO_THROW(ep.Rethrow());
  }

  TEST(ExceptionPointerTest, GetCurrentExceptionOnKnownExceptionThenRethrow) {
    ExceptionPtr ep;
    {
      try {
        throw InvalidOperationException();
      } catch (...) {
        ep = ExceptionPtr::CurrentException();
      }
    }
    ASSERT_FALSE(ep == null);
    ASSERT_THROW(ep.Rethrow(), InvalidOperationException);
  }

  TEST(ExceptionPointerTest, GetCurrentExceptionOnUnknownExceptionThenRethrow) {
    struct MyException {};
    ExceptionPtr ep;
    {
      try {
        throw MyException();
      } catch (...) {
        ep = ExceptionPtr::CurrentException();
      }
    }
    ASSERT_FALSE(ep == null);
    ASSERT_THROW(ep.Rethrow(), MyException);
  }
}
