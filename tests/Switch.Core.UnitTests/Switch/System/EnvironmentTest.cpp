#include <Switch/System/Environment.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  /*
   TEST(EnvironmentTest, GetEnvironmentVariables) {
   ASSERT_GT(Environment::GetEnvironmentVariables().Count, 0);
   } */
  
  TEST(EnvironmentTest, GetEnvironmentVariable) {
    ASSERT_FALSE(string::IsNullOrEmpty(Environment::GetEnvironmentVariable("PATH")));
  }
  
  /*
   TEST(EnvironmentTest, SetEnvironmentVariable) {
   ASSERT_TRUE(string::IsNullOrEmpty(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT")));
   ASSERT_NO_THROW(Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "1"));
   ASSERT_EQ("1", Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT"));
   ASSERT_NO_THROW(_delegate {Environment::SetEnvironmentVariable("TEST_ENVIRONEMENT", "");});
   ASSERT_TRUE(string::IsNullOrEmpty(Environment::GetEnvironmentVariable("TEST_ENVIRONEMENT")));
   } */
}

