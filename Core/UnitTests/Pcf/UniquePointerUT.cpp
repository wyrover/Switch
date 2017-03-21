#include <Pcf/UniquePointer.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

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
    pcf_using(UniquePointer<int> ptr) {
      EXPECT_THROW(ptr.ToPointer(), std::exception);
      EXPECT_TRUE(ptr.IsNull());
      EXPECT_THROW(*ptr, std::exception);
      EXPECT_THROW(ptr.ToObject(), std::exception);
    }
  }

  TEST(Up, SetNotNull) {
    TestPointer::ResetCpt();
    pcf_using(UniquePointer<TestPointer> ptr(new TestPointer())) {
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
  
    pcf_using(UniquePointer<TestPointer> ptr(tp)) {
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
    pcf_using(UniquePointer<TestPointer> ptr = new TestPointer()) {
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
    UniquePointer<TestPointer> ptr1(new TestPointer());
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    pcf_using(UniquePointer<TestPointer> ptr2(ptr1)) {
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
    UniquePointer<TestPointer> ptr1(new TestPointer());
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    pcf_using(UniquePointer<TestPointer> ptr2 = ptr1) {
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
    UniquePointer<TestPointer> ptr;
  
    EXPECT_NO_THROW(ptr.Reset());
    EXPECT_THROW(ptr.ToPointer(), std::exception);
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetFromANativePointerAndReset) {
    TestPointer::ResetCpt();
    TestPointer* pt = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());

    pcf_using(UniquePointer<TestPointer> ptr(pt)) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_NO_THROW(ptr.Reset());
      EXPECT_THROW(ptr.ToPointer(), std::exception);
      EXPECT_EQ(0, TestPointer::GetCpt());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetNullAndCheckIsNullOrEmpty) {
    UniquePointer<string> ptr;
    EXPECT_TRUE(ptr.IsNull());
  }

  TEST(Up, SetFromANativePointerAndCheckIsNullOrEmpty) {
    TestPointer::ResetCpt();
    TestPointer* pt = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    pcf_using(UniquePointer<TestPointer> ptr(pt)) {
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_EQ(1, TestPointer::GetCpt());
    }
  
    EXPECT_EQ(0, TestPointer::GetCpt());
  }

  TEST(Up, SetNullAndResetResetToANativePointer) {
    TestPointer::ResetCpt();
    TestPointer* pt = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
  
    pcf_using(UniquePointer<TestPointer> ptr) {
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
 
    pcf_using(UniquePointer<TestPointer> ptr(pt1)) {
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

    pcf_using(UniquePointer<TestPointer> ptr(pt1)) {
      UniquePointer<TestPointer> ptr2(pt2);
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
    pcf_using(UniquePointer<string> ptr(str)) {
      EXPECT_EQ(*str, ptr.ToObject());
    }
  }

  TEST(Up, SetFromANativePointerAndGetPointer) {
    string* str = new string("Test Pointer!");
    pcf_using(UniquePointer<string> ptr(str)) {
      EXPECT_EQ(str, ptr.ToPointer());
    }
  }

  TEST(Up, ToString) {
    pcf_using(UniquePointer<string> ptr) {
      EXPECT_EQ(string("Pcf::UniquePointer [Pointer=null]"), ptr.ToString().c_str());
    }

    string* str = new string("Test Pointer!");
    pcf_using(UniquePointer<string> ptr(str)) {
      EXPECT_TRUE(string(ptr.ToString().c_str()).StartsWith("Pcf::UniquePointer [Pointer="));
      EXPECT_TRUE(string(ptr.ToString().c_str()).EndsWith("]"));
      EXPECT_NE(string("Pcf::UniquePointer [Pointer=null]"), ptr.ToString().c_str());
    }

  }

}
