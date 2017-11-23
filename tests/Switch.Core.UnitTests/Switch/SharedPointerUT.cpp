#include <Switch/RefPtr.hpp>
#include <Switch/System/String.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace {
  class ParentA : public System::Object {
  
  public:
    static int32 parentAReleaseCount;
    
    ParentA() {}
    
    virtual ~ParentA() {
      ParentA::parentAReleaseCount++;
    }
  };
  
  int32 ParentA::parentAReleaseCount = 0;
  
  class ChildB: public ParentA {
  
  public:
    static int32 childBReleaseCount;
    
    ChildB() { }
    
    virtual ~ChildB() {
      ChildB::childBReleaseCount++;
    }
  };
  
  int32 ChildB::childBReleaseCount = 0;
  
  class TestPointer {
  public:
    TestPointer() : str("TestPointer") { this->cpt += 1; }
    ~TestPointer() { cpt -= 1; }
    
    static void ResetCpt() { cpt = 0; }
    static int GetCpt() { return cpt; }
    
    String ToString() const { return this->str; }
    
  private:
    static int cpt;
    string str;
  };
  
  int TestPointer::cpt = 0;
  
  TEST(RefPtrTest, SetNull) {
    _using(refptr<int> ptr) {
      ASSERT_THROW(ptr.ToPointer(), std::exception);
      ASSERT_TRUE(ptr == null);
      ASSERT_THROW(*ptr, std::exception);
      ASSERT_THROW(ptr.ToObject(), std::exception);
    }
  }
  
  TEST(RefPtrTest, SetNotNull) {
    TestPointer::ResetCpt();
    _using(refptr<TestPointer> ptr(new TestPointer())) {
      ASSERT_EQ(1, TestPointer::GetCpt());
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      ASSERT_FALSE(ptr == null);
      ASSERT_NO_THROW(*ptr);
      ASSERT_NO_THROW(ptr.ToObject());
    }
    ASSERT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(RefPtrTest, Set) {
    TestPointer::ResetCpt();
    TestPointer* tp = new TestPointer();
    ASSERT_EQ(1, TestPointer::GetCpt());
    _using(refptr<TestPointer> ptr(tp)) {
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      ASSERT_FALSE(ptr == null);
      ASSERT_NO_THROW(*ptr);
      ASSERT_NO_THROW(ptr.ToObject());
      ASSERT_EQ(tp, ptr.ToPointer());
    }
    ASSERT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(RefPtrTest, SetFromEqual) {
    TestPointer::ResetCpt();
    _using(refptr<TestPointer> ptr = new TestPointer()) {
      ASSERT_EQ(1, TestPointer::GetCpt());
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      ASSERT_FALSE(ptr == null);
      ASSERT_NO_THROW(*ptr);
      ASSERT_NO_THROW(ptr.ToObject());
    }
    ASSERT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(RefPtrTest, SetFromSharedPointer) {
    TestPointer::ResetCpt();
    _using(refptr<TestPointer> ptr1(new TestPointer())) {
      ASSERT_EQ(1, TestPointer::GetCpt());
      _using(refptr<TestPointer> ptr2(ptr1)) {
        ASSERT_EQ(1, TestPointer::GetCpt());
        ASSERT_EQ(2, ptr1.GetUseCount());
        ASSERT_EQ(2, ptr2.GetUseCount());
        EXPECT_NE((TestPointer*)null, ptr1.ToPointer());
        EXPECT_NE((TestPointer*)null, ptr2.ToPointer());
        ASSERT_TRUE(ptr1 == ptr2);
        ASSERT_FALSE(ptr1 == null);
        ASSERT_FALSE(ptr2 == null);
        ASSERT_NO_THROW(*ptr2);
        ASSERT_NO_THROW(ptr2.ToObject());
        ASSERT_EQ("TestPointer", ptr2.ToObject().ToString());
      }
      ASSERT_EQ(1, TestPointer::GetCpt());
      ASSERT_EQ(1, ptr1.GetUseCount());
      ASSERT_EQ("TestPointer", ptr1.ToObject().ToString());
    }
    ASSERT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(RefPtrTest, SetFromEqualSharedPointer) {
    TestPointer::ResetCpt();
    _using(refptr<TestPointer> ptr1(new TestPointer())) {
      ASSERT_EQ(1, TestPointer::GetCpt());
      _using(refptr<TestPointer> ptr2 = ptr1) {
        ASSERT_EQ(1, TestPointer::GetCpt());
        ASSERT_EQ(2, ptr1.GetUseCount());
        ASSERT_EQ(2, ptr2.GetUseCount());
        EXPECT_NE((TestPointer*)null, ptr1.ToPointer());
        EXPECT_NE((TestPointer*)null, ptr2.ToPointer());
        ASSERT_TRUE(ptr1 == ptr2);
        ASSERT_FALSE(ptr1 == null);
        ASSERT_FALSE(ptr2 == null);
        ASSERT_NO_THROW(*ptr2);
        ASSERT_NO_THROW(ptr2.ToObject());
        ASSERT_EQ("TestPointer", ptr2.ToObject().ToString());
      }
      ASSERT_EQ(1, TestPointer::GetCpt());
      ASSERT_EQ(1, ptr1.GetUseCount());
      ASSERT_EQ("TestPointer", ptr1.ToObject().ToString());
    }
    ASSERT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(RefPtrTest, Constructor) {
    refptr<string> stringEmpty;
    ASSERT_TRUE(stringEmpty == null);
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(stringEmpty));
    ASSERT_THROW(stringEmpty.ToObject(), std::exception);
    ASSERT_THROW(stringEmpty.ToPointer(), std::exception);
    ASSERT_EQ(0, stringEmpty.GetUseCount());
    ASSERT_THROW(*stringEmpty, std::exception);
    ASSERT_THROW(stringEmpty->Length(), std::exception);
    ASSERT_THROW((*stringEmpty)[0], std::exception);
    
    refptr<string> stringEmpty2(refptr<string>::Empty());
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(stringEmpty2));
    ASSERT_THROW(stringEmpty2.ToObject(), std::exception);
    ASSERT_THROW(stringEmpty2.ToPointer(), std::exception);
    ASSERT_EQ(0, stringEmpty2.GetUseCount());
    ASSERT_THROW(*stringEmpty2, std::exception);
    ASSERT_THROW(stringEmpty2->Length(), std::exception);
    ASSERT_THROW((*stringEmpty2)[0], std::exception);
    
    refptr<string> stringNull(null);
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(stringNull));
    ASSERT_THROW(stringNull.ToObject(), std::exception);
    ASSERT_THROW(stringNull.ToPointer(), std::exception);
    ASSERT_EQ(0, stringNull.GetUseCount());
    ASSERT_THROW(*stringNull, std::exception);
    ASSERT_THROW(stringNull->Length(), std::exception);
    ASSERT_THROW((*stringNull)[0], std::exception);
    
    refptr<string> str(new string("Test Share Pointer"));
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("Test Share Pointer", str.ToObject());
    ASSERT_EQ("Test Share Pointer", *str.ToPointer());
    ASSERT_EQ(1, str.GetUseCount());
    ASSERT_EQ("Test Share Pointer", *str);
    ASSERT_EQ(18, str->Length());
    ASSERT_EQ('T', (*str)[0]);
    
    refptr<string> str2 = new string("Test an other Share Pointer");
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str2));
    ASSERT_EQ("Test an other Share Pointer", str2.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str2.ToPointer());
    ASSERT_EQ(1, str2.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str2);
    ASSERT_EQ(27, str2->Length());
    ASSERT_EQ('T', (*str2)[0]);
    
    refptr<string> str3(str);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("Test Share Pointer", str.ToObject());
    ASSERT_EQ("Test Share Pointer", *str.ToPointer());
    ASSERT_EQ(2, str.GetUseCount());
    ASSERT_EQ(*str, "Test Share Pointer");
    ASSERT_EQ(18, str->Length());
    ASSERT_EQ('T', (*str)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test Share Pointer", str3.ToObject());
    ASSERT_EQ("Test Share Pointer", *str3.ToPointer());
    ASSERT_EQ(2, str3.GetUseCount());
    ASSERT_EQ("Test Share Pointer", *str3);
    ASSERT_EQ(18, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
  }
  
  TEST(RefPtrTest, Equal) {
    refptr<string> stringEmpty = refptr<string>::Empty();
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(stringEmpty));
    ASSERT_THROW(stringEmpty.ToObject(), std::exception);
    ASSERT_THROW(stringEmpty.ToPointer(), std::exception);
    ASSERT_EQ(0, stringEmpty.GetUseCount());
    ASSERT_THROW(*stringEmpty, std::exception);
    ASSERT_THROW(stringEmpty->Length(), std::exception);
    ASSERT_THROW((*stringEmpty)[0], std::exception);
    
    refptr<string> stringNull = refptr<String>::Null();
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(stringNull));
    ASSERT_THROW(stringNull.ToObject(), std::exception);
    ASSERT_THROW(stringNull.ToPointer(), std::exception);
    ASSERT_EQ(0, stringNull.GetUseCount());
    ASSERT_THROW(*stringNull, std::exception);
    ASSERT_THROW(stringNull->Length(), std::exception);
    ASSERT_THROW((*stringNull)[0], std::exception);
    
    refptr<string> str = new string("Test Share Pointer");
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("Test Share Pointer", str.ToObject());
    ASSERT_EQ("Test Share Pointer", *str.ToPointer());
    ASSERT_EQ(1, str.GetUseCount());
    ASSERT_EQ("Test Share Pointer", *str);
    ASSERT_EQ(18, str->Length());
    ASSERT_EQ('T', (*str)[0]);
    
    refptr<string> str2 = new string("Test an other Share Pointer");
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str2));
    ASSERT_EQ("Test an other Share Pointer", str2.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str2.ToPointer());
    ASSERT_EQ(1, str2.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str2);
    ASSERT_EQ(27, str2->Length());
    ASSERT_EQ('T', (*str2)[0]);
    
    refptr<string> str3 = str;
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("Test Share Pointer", str.ToObject());
    ASSERT_EQ("Test Share Pointer", *str.ToPointer());
    ASSERT_EQ(2, str.GetUseCount());
    ASSERT_EQ("Test Share Pointer", *str);
    ASSERT_EQ(18, str->Length());
    ASSERT_EQ('T', (*str)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test Share Pointer", str3.ToObject());
    ASSERT_EQ("Test Share Pointer", *str3.ToPointer());
    ASSERT_EQ(2, str3.GetUseCount());
    ASSERT_EQ("Test Share Pointer", *str3);
    ASSERT_EQ(18, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    ASSERT_EQ(2, str.GetUseCount());
    
    *str = "This is a new Value for the Share Pointer";
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("This is a new Value for the Share Pointer", str.ToObject());
    ASSERT_EQ("This is a new Value for the Share Pointer", *str.ToPointer());
    ASSERT_EQ(2, str.GetUseCount());
    ASSERT_EQ("This is a new Value for the Share Pointer", *str);
    ASSERT_EQ(41, str->Length());
    ASSERT_EQ('T', (*str)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("This is a new Value for the Share Pointer", str3.ToObject());
    ASSERT_EQ("This is a new Value for the Share Pointer", *str3.ToPointer());
    ASSERT_EQ(2, str3.GetUseCount());
    ASSERT_EQ("This is a new Value for the Share Pointer", *str3);
    ASSERT_EQ(41, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    ASSERT_EQ(2, str.GetUseCount());
    
    *str3 = "And an other one";
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("And an other one", str.ToObject());
    ASSERT_EQ("And an other one", *str.ToPointer());
    ASSERT_EQ(2, str.GetUseCount());
    ASSERT_EQ("And an other one", *str);
    ASSERT_EQ(16, str->Length());
    ASSERT_EQ('A', (*str)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("And an other one", str3.ToObject());
    ASSERT_EQ("And an other one", *str3.ToPointer());
    ASSERT_EQ(2, str3.GetUseCount());
    ASSERT_EQ("And an other one", *str3);
    ASSERT_EQ(16, str3->Length());
    ASSERT_EQ('A', (*str3)[0]);
    ASSERT_EQ(2, str.GetUseCount());
    
    str3 = str2;
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("And an other one", str.ToObject());
    ASSERT_EQ("And an other one", *str.ToPointer());
    ASSERT_EQ(1, str.GetUseCount());
    ASSERT_EQ("And an other one", *str);
    ASSERT_EQ(16, str->Length());
    ASSERT_EQ('A', (*str)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str2));
    ASSERT_EQ("Test an other Share Pointer", str2.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str2.ToPointer());
    ASSERT_EQ(2, str2.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str2);
    ASSERT_EQ(27, str2->Length());
    ASSERT_EQ('T', (*str2)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test an other Share Pointer", str3.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str3.ToPointer());
    ASSERT_EQ(2, str3.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str3);
    ASSERT_EQ(27, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    
    str2 = refptr<string>::Null();
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str));
    ASSERT_EQ("And an other one", str.ToObject());
    ASSERT_EQ("And an other one", *str.ToPointer());
    ASSERT_EQ(1, str.GetUseCount());
    ASSERT_EQ("And an other one", *str);
    ASSERT_EQ(16, str->Length());
    ASSERT_EQ('A', (*str)[0]);
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(str2));
    ASSERT_THROW(str2.ToObject(), std::exception);
    ASSERT_THROW(str2.ToPointer(), std::exception);
    ASSERT_EQ(0, str2.GetUseCount());
    ASSERT_THROW(*str2, std::exception);
    ASSERT_THROW(str2->Length(), std::exception);
    ASSERT_THROW((*str2)[0], std::exception);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test an other Share Pointer", str3.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str3.ToPointer());
    ASSERT_EQ(1, str3.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str3);
    ASSERT_EQ(27, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    
    refptr<string> str4 = str3;
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test an other Share Pointer", str3.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str3.ToPointer());
    ASSERT_EQ(2, str3.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str3);
    ASSERT_EQ(27, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str4));
    ASSERT_EQ("Test an other Share Pointer", str4.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str4.ToPointer());
    ASSERT_EQ(2, str4.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str4);
    ASSERT_EQ(27, str4->Length());
    ASSERT_EQ('T', (*str4)[0]);
    
    str4 = refptr<string>::Empty();
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test an other Share Pointer", str3.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str3.ToPointer());
    ASSERT_EQ(1, str3.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str3);
    ASSERT_EQ(27, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    ASSERT_TRUE(refptr<string>::IsNullOrInvalid(str4));
    ASSERT_THROW(str4.ToObject(), std::exception);
    ASSERT_THROW(str4.ToPointer(), std::exception);
    ASSERT_EQ(0, str4.GetUseCount());
    ASSERT_THROW(*str4, std::exception);
    ASSERT_THROW(str4->Length(), std::exception);
    ASSERT_THROW((*str4)[0], std::exception);
    
    refptr<string> str5 = str3;
    refptr<string> str6 = str5;
    refptr<string> str7 = str3;
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    ASSERT_EQ("Test an other Share Pointer", str3.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str3.ToPointer());
    ASSERT_EQ(4, str3.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str3);
    ASSERT_EQ(27, str3->Length());
    ASSERT_EQ('T', (*str3)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str5));
    ASSERT_EQ("Test an other Share Pointer", str5.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str5.ToPointer());
    ASSERT_EQ(str5.GetUseCount(), 4);
    ASSERT_EQ("Test an other Share Pointer", *str5);
    ASSERT_EQ(27, str5->Length());
    ASSERT_EQ('T', (*str5)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str6));
    ASSERT_EQ("Test an other Share Pointer", str6.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str6.ToPointer());
    ASSERT_EQ(4, str6.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str6);
    ASSERT_EQ(27, str6->Length());
    ASSERT_EQ('T', (*str6)[0]);
    ASSERT_FALSE(refptr<string>::IsNullOrInvalid(str7));
    ASSERT_EQ("Test an other Share Pointer", str7.ToObject());
    ASSERT_EQ("Test an other Share Pointer", *str7.ToPointer());
    ASSERT_EQ(4, str7.GetUseCount());
    ASSERT_EQ("Test an other Share Pointer", *str7);
    ASSERT_EQ(27, str7->Length());
    ASSERT_EQ('T', (*str7)[0]);
  }
  
  TEST(RefPtrTest, Null) {
    /*
     refptr<string> stringNull;
     ASSERT_TRUE(stringNull == IntPtr::Zero);
     ASSERT_TRUE(stringNull == IntPtr(null));
     ASSERT_TRUE(!stringNull);
     ASSERT_FALSE(stringNull != IntPtr::Zero);
     ASSERT_FALSE(stringNull != IntPtr(null));
     ASSERT_FALSE(stringNull);
    
     refptr<string> str =new string();
     ASSERT_FALSE(str == IntPtr::Zero);
     ASSERT_FALSE(str == IntPtr(null));
     ASSERT_FALSE(!str);
     ASSERT_TRUE(str != IntPtr::Zero);
     ASSERT_TRUE(str != IntPtr(null));
     ASSERT_TRUE(str);
     */
  }
  
  TEST(RefPtrTest, Cast) {
    refptr<string> str = new string("Test for cast");
    string strCopy;
    
    ASSERT_EQ("Test for cast", *str);
    strCopy = *str;
    ASSERT_EQ("Test for cast", strCopy);
  }
  
  TEST(RefPtrTest, Release) {
    ParentA::parentAReleaseCount = 0;
    {
      refptr<ParentA> parentA = new ParentA();
      refptr<ParentA> parentA1 = new ParentA();
      ASSERT_EQ(0, ParentA::parentAReleaseCount);
    }
    ASSERT_EQ(2, ParentA::parentAReleaseCount);
  }
  
  TEST(RefPtrTest, Copy) {
    ParentA::parentAReleaseCount = 0;
    {
      refptr<ParentA> parentA = new ParentA();
      refptr<ParentA> parentA1(parentA);
      ASSERT_EQ(0, ParentA::parentAReleaseCount);
    }
    ASSERT_EQ(1, ParentA::parentAReleaseCount);
  }
  
  TEST(RefPtrTest, Affectation) {
    ParentA::parentAReleaseCount = 0;
    {
      refptr<ParentA> parentA = new ParentA();
      refptr<ParentA> parentA1 = parentA;
      ASSERT_EQ(0, ParentA::parentAReleaseCount);
    }
    ASSERT_EQ(1, ParentA::parentAReleaseCount);
  }
  
  TEST(RefPtrTest, Cast2) {
    ParentA::parentAReleaseCount = 0;
    ChildB::childBReleaseCount = 0;
    {
      refptr<ChildB> childB = new ChildB();
      refptr<ParentA> parentA = childB.ChangeType<ParentA>();
      ASSERT_EQ(0, ParentA::parentAReleaseCount);
      ASSERT_EQ(0, ChildB::childBReleaseCount);
    }
    ASSERT_EQ(1, ParentA::parentAReleaseCount);
    ASSERT_EQ(1, ChildB::childBReleaseCount);
  }
  
  TEST(RefPtrTest, ToObjectTT) {
    refptr<string> spString(new string("Hello World"));
    refptr<Object> obj = spString.ChangeType<Object>();
    string str = obj.ToObject<string>();
    ASSERT_TRUE(str.Equals("Hello World"));
    ASSERT_THROW(obj.ToObject<Int32>(), std::exception);
  }
  
  TEST(RefPtrTest, ToPointerTT) {
    refptr<string> spString(new string("Hello World"));
    refptr<Object> obj = spString.ChangeType<Object>();
    string* str = obj.ToPointer<string>();
    ASSERT_TRUE(str->Equals("Hello World"));
  }
  
  TEST(RefPtrTest, Equality) {
    Switch::refptr<std::string> s1 = new std::string("string 1");
  }
  
  TEST(RefPtrTest, CopyCast) {
    ParentA::parentAReleaseCount = 0;
    ChildB::childBReleaseCount = 0;
    {
      refptr<ChildB> childB = new ChildB();
      //refptr<ParentA> parentA(childB);
      refptr<ParentA> parentA = childB.ChangeType<ParentA>();
      
      ASSERT_EQ(0, ParentA::parentAReleaseCount);
      ASSERT_EQ(0, ChildB::childBReleaseCount);
    }
    ASSERT_EQ(1, ParentA::parentAReleaseCount);
    ASSERT_EQ(1, ChildB::childBReleaseCount);
  }
}
