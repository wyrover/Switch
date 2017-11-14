/// @file
/// @brief Contains Switch::TUnit::TestFixture class.
#pragma once

#include <gtest/gtest.h>
#include <Switch/System/Object.hpp>
#include <Switch/System/String.hpp>
#include <Switch/System/SystemException.hpp>

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #_AddTest method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #_AddTest method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The base class that all unit tests inherit from.
    /// This example code shows how to use TestFixture class:
    /// @include TestFixture.cpp
    class _export TestFixture : public testing::Test {
    protected:
      /// @cond
      TestFixture() {}
      TestFixture(const TestFixture&) = delete;
      TestFixture& operator =(const TestFixture&) = delete;
      /// @endcond
      
      /// @brief This is the method that is called before any tests in a fixture are run. Override it for used.
      void SetUp() override {}

      /// @brief This is the method that is called after any tests in a fixture are run. Override it for used.
      void TearDown() override {}
    };

    
    #define _TestFixture(name) \
    name##_unused {}; \
    struct name : public TUnit::TestFixture
    
    #define _SetUp(name) \
    SetUp() override {name();} \
    void name()
    
    #define _TearDown(name) \
    TearDown() override {name();} \
    void name()
    
    #define _Test(name) \
    name()

    #define _IgnoreTest(name) \
    name()
    
    #define _AddTestFixture(name)

    /// @brief Add spacified unit test to execute at the unit test suit.
    /// @param fixture The class inerited from TestFixture class that contains the unit test method to execute
    /// @param method The method that contains the unit test to execute
    /// @par Examples
    /// This example how to use TestFixture class, Expect class and #_AddTest method:
    /// @include Expect.cpp
    /// @ingroup TUnit
    #define _AddTest(fixture, method) \
    GTEST_TEST_(fixture, method, fixture, ::testing::internal::GetTypeId<fixture>()) { \
      try { \
        method(); \
      } catch(const TUnit::AssertionException) { \
        return ; \
      } \
    }
    
    /// @brief Add specified ignored unit test to execute at the unit test suit.
    /// @param fixture The class inerited from TestFixture class that contains the unit test method to execute
    /// @param method The method that contains the unit test to execute
    /// @par Examples
    /// This example how to use TestFixture class, Expect class and #_AddTest method:
    /// @include Expect.cpp
    /// @ingroup TUnit
    #define _add_ignore_test(fixture, method) \
    GTEST_TEST_(fixture, DISABLED_##method, fixture, ::testing::internal::GetTypeId<fixture>()) { \
      try { \
        method(); \
      } catch(const TUnit::AssertionException) { \
        return ; \
      } \
    }
  }
}

using namespace Switch;
