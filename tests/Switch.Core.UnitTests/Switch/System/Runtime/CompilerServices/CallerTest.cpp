#include <Switch/Boxing.hpp>
#include <gtest/gtest.h>

using namespace System;
using namespace System::Runtime::CompilerServices;

namespace SwitchUnitTests {
  TEST(CallerTest, CreateAnEmptyCallerThenToString) {
    Caller ci;
    ASSERT_EQ("{Empty}", ci.ToString());
  }

  TEST(CallerTest, CreateAnEmptyCallerThenGetFileName) {
    Caller ci;
    ASSERT_EQ("", ci.FilePath);
  }

  TEST(CallerTest, CreateAnEmptyCallerThenGetFunctionName) {
    Caller ci;
    ASSERT_EQ("", ci.MemberNamne);
  }

  TEST(CallerTest, CreateAnEmptyCallerThenGetLine) {
    Caller ci;
    ASSERT_EQ(0, ci.LineNumber);
  }

  TEST(CallerTest, CreateCallerWithFileNameAndLineThenToString) {
    Caller ci("MyFile.txt", 42);
    ASSERT_EQ("{FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString());
  }

  TEST(CallerTest, CreateCallerWithFileNameAndLineThenGetFileName) {
    Caller ci("MyFile.txt", 42);
    ASSERT_EQ("MyFile.txt", ci.FilePath);
  }

  TEST(CallerTest, CreateCallerWithFileNameAndLineThenGetFunctionName) {
    Caller ci("MyFile.txt", 42);
    ASSERT_EQ("", ci.MemberNamne);
  }

  TEST(CallerTest, CreateCallerWithFileNameAndLineThenGetLine) {
    Caller ci("MyFile.txt", 42);
    ASSERT_EQ(42, ci.LineNumber);
  }

  TEST(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenToString) {
    Caller ci("TEST(CallerTest, MyFunction()", "MyFile.txt", 42);
    ASSERT_EQ("{MemberName=\"TEST(CallerTest, MyFunction()\", FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString());
  }

  TEST(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenGetFileName) {
    Caller ci("TEST(CallerTest, MyFunction()", "MyFile.txt", 42);
    ASSERT_EQ("MyFile.txt", ci.FilePath);
  }

  TEST(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenGetFunctionName) {
    Caller ci("TEST(CallerTest, MyFunction()", "MyFile.txt", 42);
    ASSERT_EQ("TEST(CallerTest, MyFunction()", ci.MemberNamne);
  }

  TEST(CallerTest, CreateCallerWithFileNameLineAndFunctionNameThenGetLine) {
    Caller ci("TEST(CallerTest, MyFunction()", "MyFile.txt", 42);
    ASSERT_EQ(42, ci.LineNumber);
  }

  TEST(CallerTest, CreateCallerByCopyConstructorThenToString) {
    Caller ci = Caller("TEST(CallerTest, MyFunction()", "MyFile.txt", 42);
    ASSERT_EQ("{MemberName=\"TEST(CallerTest, MyFunction()\", FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString());
  }

  TEST(CallerTest, CreateCallerByCopyOperatorThenToString) {
    Caller ci;
    ci = Caller("TEST(CallerTest, MyFunction()", "MyFile.txt", 42);
    ASSERT_EQ("{MemberName=\"TEST(CallerTest, MyFunction()\", FilePath=\"MyFile.txt\", LineNumber=42}", ci.ToString());
  }
}

