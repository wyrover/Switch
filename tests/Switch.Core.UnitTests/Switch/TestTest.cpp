// Internal Test (Remove comment to test...)
/*
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

class GTestTest : public testing::Test {
protected:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(GTestTest, AreEqualInt32) {
  ASSERT_EQ(41, int32(42));
  ASSERT_EQ(43, int32(42));
  ASSERT_EQ(42, int32(42));
}

TEST_F(GTestTest, AreNotEqualInt32) {
  ASSERT_EQ(42, int32(42));
  ASSERT_EQ(41, int32(42));
}

TEST_F(GTestTest, AreEqualtring) {
  ASSERT_EQ("Tes", string("Test"));
  ASSERT_EQ("Test", string("Test"));
}

TEST_F(GTestTest, AreNotEqualString) {
  ASSERT_EQ("Test", string("Test"));
  ASSERT_EQ("Tes", string("Test"));
}

TEST_F(GTestTest, ThrowException) {
  throw ArgumentNullException(caller_);
}

TEST_F(GTestTest, IsTrueBoolean) {
  ASSERT_TRUE(true);
  ASSERT_TRUE(false);
}

TEST_F(GTestTest, ThrowArgumentNullException) {
  ASSERT_THROW(throw ArgumentNullException(caller_), ArgumentNullException);
}

TEST_F(GTestTest, ThrowIndexOutOfRangeException) {
  ASSERT_THROW(throw ArgumentNullException(caller_), IndexOutOfRangeException);
}

namespace SwitchUnitTests {
  class TUnitTest : public TestFixture {
  public:
    void SetUp() override {}

    void TearDown() override {}

    void AreEqualInt32() {
      Assert::AreEqual(41, int32(42));
      Assert::AreEqual(43, int32(42));
      Assert::AreEqual(42, int32(42));
    }

    void AreNotEqualInt32() {
      Assert::AreNotEqual(42, int32(42));
      Assert::AreNotEqual(41, int32(42));
    }

    void AreEqualtring() {
      Assert::AreEqual("Tes", string("Test"));
      Assert::AreEqual("Test", string("Test"));
    }

    void AreNotEqualString() {
      Assert::AreNotEqual("Test", string("Test"));
      Assert::AreNotEqual("Tes", string("Test"));
    }

    void ThrowException() {
      throw ArgumentNullException(caller_);
    }

    void IsTrueBoolean() {
      Assert::IsTrue(true);
    }

    void ThrowArgumentNullException() {
      Assert::Throws<ArgumentNullException>(delegate_ {throw ArgumentNullException(caller_);}, caller_);
    }

    void ThrowIndexOutOfRangeException() {
      Assert::Throws<IndexOutOfRangeException>(delegate_ {throw ArgumentNullException(caller_);}, caller_);
    }
  };

  AddTest_(TUnitTest, AreEqualInt32);
  AddTest_(TUnitTest, AreNotEqualInt32);
  AddTest_(TUnitTest, AreEqualtring);
  AddTest_(TUnitTest, AreNotEqualString);
  AddTest_(TUnitTest, ThrowException);
  AddTest_(TUnitTest, IsTrueBoolean);
  AddTest_(TUnitTest, ThrowArgumentNullException);
  AddTest_(TUnitTest, ThrowIndexOutOfRangeException);
}
*/
