#include <Switch/UniquePtr.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  class TestPointer {
  public:
    TestPointer() { cpt += 1; }
    ~TestPointer() { cpt -= 1; }
    
    static void ResetCpt() { cpt = 0; }
    static int GetCpt() { return cpt; }
    
  private:
    static int cpt;
  };

  int TestPointer::cpt = 0;

  TEST(Up, SetNull) {
    sw_using(UniquePtr<int> ptr) {
      EXPECT_THROW(ptr.ToPointer(), std::exception);
      EXPECT_TRUE(ptr.IsNull());
      EXPECT_THROW(*ptr, std::exception);
      EXPECT_THROW(ptr.ToObject(), std::exception);
    }
  }

  TEST(Up, SetNotNull) {
    TestPointer::ResetCpt();
    sw_using(UniquePtr<TestPointer> ptr(new TestPointer())) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_NO_THROW(*ptr);
      EXPECT_NO_THROW(ptr.ToObject());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, FromANativePointer) {
    TestPointer::ResetCpt();
    TestPointer* tp = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    sw_using(UniquePtr<TestPointer> ptr(tp)) {
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_NO_THROW(*ptr);
      EXPECT_NO_THROW(ptr.ToObject());
      EXPECT_EQ(tp, ptr.ToPointer());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, FromEqual) {
    TestPointer::ResetCpt();
    sw_using(UniquePtr<TestPointer> ptr = new TestPointer()) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_NO_THROW(*ptr);
      EXPECT_NO_THROW(ptr.ToObject());
     }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, FromUniquePointer) {
    TestPointer::ResetCpt();
    UniquePtr<TestPointer> ptr1(new TestPointer());
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    sw_using(UniquePtr<TestPointer> ptr2(ptr1)) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_THROW(ptr1.ToPointer(), std::exception);
      EXPECT_NE((TestPointer*)null, ptr2.ToPointer());
      EXPECT_FALSE(ptr2.IsNull());
      EXPECT_NO_THROW(*ptr2);
      EXPECT_NO_THROW(ptr2.ToObject());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, FromEqualUniquePointer) {
    TestPointer::ResetCpt();
    UniquePtr<TestPointer> ptr1(new TestPointer());
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    sw_using(UniquePtr<TestPointer> ptr2 = ptr1) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_THROW(ptr1.ToPointer(), std::exception);
      EXPECT_NE((TestPointer*)null, ptr2.ToPointer());
      EXPECT_FALSE(ptr2.IsNull());
      EXPECT_NO_THROW(*ptr2);
      EXPECT_NO_THROW(ptr2.ToObject());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetAndReset) {
    TestPointer::ResetCpt();
    UniquePtr<TestPointer> ptr;
  
    EXPECT_NO_THROW(ptr.Reset());
    EXPECT_THROW(ptr.ToPointer(), std::exception);
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetFromANativePointerAndReset) {
    TestPointer::ResetCpt();
    TestPointer* pt = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());

    sw_using(UniquePtr<TestPointer> ptr(pt)) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_NO_THROW(ptr.Reset());
      EXPECT_THROW(ptr.ToPointer(), std::exception);
      EXPECT_EQ(0, TestPointer::GetCpt());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetNullAndCheckIsNullOrEmpty) {
    UniquePtr<string> ptr;
    EXPECT_TRUE(ptr.IsNull());
  }

  TEST(Up, SetFromANativePointerAndCheckIsNullOrEmpty) {
    TestPointer::ResetCpt();
    TestPointer* pt = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    sw_using(UniquePtr<TestPointer> ptr(pt)) {
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_EQ(1, TestPointer::GetCpt());
    }
  
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetNullAndResetResetToANativePointer) {
    TestPointer::ResetCpt();
    TestPointer* pt = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    sw_using(UniquePtr<TestPointer> ptr) {
      EXPECT_NO_THROW(ptr.Reset(pt));
      EXPECT_EQ(pt, ptr.ToPointer());
      EXPECT_EQ(1, TestPointer::GetCpt());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetFromANativePointerAndResetToANativePointer) {
    TestPointer::ResetCpt();
    TestPointer* pt1 = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
    TestPointer* pt2 = new TestPointer();
    EXPECT_EQ(2, TestPointer::GetCpt());
 
    sw_using(UniquePtr<TestPointer> ptr(pt1)) {
      EXPECT_EQ(2, TestPointer::GetCpt());
      EXPECT_NO_THROW(ptr.Reset(pt2));
      EXPECT_EQ(pt2, ptr.ToPointer());
      EXPECT_EQ(1, TestPointer::GetCpt());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetTwoFromANativePointerAndSwap) {
    TestPointer::ResetCpt();
    TestPointer* pt1 = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
    TestPointer* pt2 = new TestPointer();
    EXPECT_EQ(2, TestPointer::GetCpt());

    sw_using(UniquePtr<TestPointer> ptr(pt1)) {
      UniquePtr<TestPointer> ptr2(pt2);
      EXPECT_EQ(2, TestPointer::GetCpt());
      EXPECT_NO_THROW(ptr.Swap(ptr2));
      EXPECT_EQ(pt1, ptr2.ToPointer());
      EXPECT_EQ(pt2, ptr.ToPointer());
      EXPECT_EQ(2, TestPointer::GetCpt());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetFromANativePointerAndGetValue) {
    string* str = new string("Test Pointer!");
    sw_using(UniquePtr<string> ptr(str)) {
      EXPECT_EQ(*str, ptr.ToObject());
    }
  }

  TEST(Up, SetFromANativePointerAndGetPointer) {
    string* str = new string("Test Pointer!");
    sw_using(UniquePtr<string> ptr(str)) {
      EXPECT_EQ(str, ptr.ToPointer());
    }
  }

  TEST(Up, ToString) {
    sw_using(UniquePtr<string> ptr) {
      EXPECT_EQ(string("Switch::UniquePtr [Pointer=null]"), ptr.ToString().c_str());
    }

    string* str = new string("Test Pointer!");
    sw_using(UniquePtr<string> ptr(str)) {
      EXPECT_TRUE(string(ptr.ToString().c_str()).StartsWith("Switch::UniquePtr [Pointer="));
      EXPECT_TRUE(string(ptr.ToString().c_str()).EndsWith("]"));
      EXPECT_NE(string("Switch::UniquePtr [Pointer=null]"), ptr.ToString().c_str());
    }

  }

}
