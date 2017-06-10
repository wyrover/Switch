// Internal Test (Remove comment to test...)
/*
#include <Pcf/TUnit/Assert.hpp>
#include <Pcf/TUnit/TestFixture.hpp>

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
  throw ArgumentNullException(pcf_current_information);
}

TEST_F(GTestTest, IsTrueBoolean) {
  ASSERT_TRUE(true);
  ASSERT_TRUE(false);
}

TEST_F(GTestTest, ThrowArgumentNullException) {
  ASSERT_THROW(throw ArgumentNullException(pcf_current_information), ArgumentNullException);
}

TEST_F(GTestTest, ThrowIndexOutOfRangeException) {
  ASSERT_THROW(throw ArgumentNullException(pcf_current_information), IndexOutOfRangeException);
}

namespace PcfUnitTests {
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
      throw ArgumentNullException(pcf_current_information);
    }
    
    void IsTrueBoolean() {
      Assert::IsTrue(true);
    }
    
    void ThrowArgumentNullException() {
      Assert::Throws<ArgumentNullException>(pcf_delegate {throw ArgumentNullException(pcf_current_information);}, pcf_current_information);
    }
    
    void ThrowIndexOutOfRangeException() {
      Assert::Throws<IndexOutOfRangeException>(pcf_delegate {throw ArgumentNullException(pcf_current_information);}, pcf_current_information);
    }
  };
  
  pcf_test(TUnitTest, AreEqualInt32);
  pcf_test(TUnitTest, AreNotEqualInt32);
  pcf_test(TUnitTest, AreEqualtring);
  pcf_test(TUnitTest, AreNotEqualString);
  pcf_test(TUnitTest, ThrowException);
  pcf_test(TUnitTest, IsTrueBoolean);
  pcf_test(TUnitTest, ThrowArgumentNullException);
  pcf_test(TUnitTest, ThrowIndexOutOfRangeException);
}
*/
