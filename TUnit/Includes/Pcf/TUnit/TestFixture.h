/// @file
/// @brief Contains Pcf::TUnit::TestFixture class.
#pragma once

#include <gtest/gtest.h>
#include <Pcf/System/Object.h>
#include <Pcf/System/String.h>
#include <Pcf/System/SystemException.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The TUnit namespace contains a unit test framework.
  /// @par Examples
  /// This example how to use TestFixture class, Assert class and #pcf_test method:
  /// @include Assert.cpp
  /// @par Examples
  /// This example how to use TestFixture class, Expect class and #pcf_test method:
  /// @include Expect.cpp
  namespace TUnit {
    /// @brief The base class that all unit tests inherit from.
    /// This example how to use TestFixture class:
    /// @include Assert.cpp
    class pcf_public TestFixture : public testing::Test {
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

    /// @brief Add spacified unit test to execute at the unit test suit.
    /// @param fixture The class inerited from TestFixture class that contains the unit test method to execute
    /// @param method The method that contains the unit test to execute
    /// @par Examples
    /// This example how to use TestFixture class, Expect class and #pcf_test method:
    /// @include Expect.cpp
    /// @ingroup Pcf
    #define pcf_test(fixture, method) \
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
    /// This example how to use TestFixture class, Expect class and #pcf_test method:
    /// @include Expect.cpp
    /// @ingroup Pcf
    #define pcf_ignore_test(fixture, method) \
    GTEST_TEST_(fixture, DISABLED_##method, fixture, ::testing::internal::GetTypeId<fixture>()) { \
      try { \
        method(); \
      } catch(const TUnit::AssertionException) { \
        return ; \
      } \
    }
  }
}

using namespace Pcf;
