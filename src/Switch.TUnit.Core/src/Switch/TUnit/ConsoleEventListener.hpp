/// @file
/// @brief Contains Switch::TUnit::ConsoleEventListener class.
#pragma once

#include <gtest/gtest.h>
#include <Switch/System/ConsoleColor.hpp>
#include <Switch/System/String.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @remarks This example how to use TestFixture class, Assert class and #AddTest_ method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #AddTest_ method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The ConsoleEventListener class is used to tracing execution of tests. The methods are organized in the order the corresponding events are fired.
    class ConsoleEventListener : public testing::TestEventListener {
    public:
      ConsoleEventListener();

      /// @brief Fired before any test activity starts.
      void OnTestProgramStart(const testing::UnitTest& unitTest) override;

      /// @brief Fired before each iteration of tests starts.  There may be more than one iteration if GTEST_FLAG(repeat) is set. iteration is the iteration index, starting from 0.
      void OnTestIterationStart(const testing::UnitTest& unitTest, int iteration) override;

      /// @brief Fired before environment set-up for each iteration of tests starts.
      void OnEnvironmentsSetUpStart(const testing::UnitTest& unitTest) override;

      /// @brief Fired after environment set-up for each iteration of tests ends.
      void OnEnvironmentsSetUpEnd(const testing::UnitTest& unitTest) override;

      /// @brief Fired before the test case starts.
      void OnTestCaseStart(const testing::TestCase& testCase) override;

      /// @brief Fired before the test starts.
      void OnTestStart(const testing::TestInfo& testInfo) override;

      /// @brief Fired after a failed assertion or a SUCCEED() invocation.
      void OnTestPartResult(const testing::TestPartResult& testPartResult) override;

      /// @brief Fired after the test ends.
      void OnTestEnd(const testing::TestInfo& testInfo) override;

      /// @brief Fired after the test case ends.
      void OnTestCaseEnd(const testing::TestCase& testCase) override;

      /// @brief Fired before environment tear-down for each iteration of tests starts.
      void OnEnvironmentsTearDownStart(const testing::UnitTest& unitTest) override;

      /// @brief Fired after environment tear-down for each iteration of tests ends.
      void OnEnvironmentsTearDownEnd(const testing::UnitTest& unitTest) override;

      /// @brief Fired after each iteration of tests finishes.
      void OnTestIterationEnd(const testing::UnitTest& unitTest, int iteration) override;

      /// @brief Fired after all test activities have ended.
      void OnTestProgramEnd(const testing::UnitTest& unitTest) override;

      static testing::TestEventListeners& ReplaceDefaultGTestListener();

      static testing::TestEventListeners& AddToGTestListener();

      static void ShowHelp();

      static void ShowVersion();

    protected:
      static void Write(System::ConsoleColor color, const System::String& value);
      static void WriteLine(System::ConsoleColor color, const System::String& value);
      static void Write(const System::String& value);
      static void WriteLine(const System::String& value);
      static void WriteLine();
    };
  }
}

using namespace Switch;
