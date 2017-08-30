#include <Switch/RefPtr.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace TUnit;

namespace {
  
  class ParentA : public System::Object {
    
  public:
    static int32 parentAReleaseCount;
    
    ParentA() {}
    
    virtual ~ParentA() {
      ParentA::parentAReleaseCount++;
    }
  };
  
  int32 ParentA::parentAReleaseCount=0;
  
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
  
  TEST(Sp, SetNull) {
    pcf_using(refptr<int> ptr) {
      EXPECT_THROW(ptr.ToPointer(), std::exception);
      EXPECT_TRUE(ptr.IsNull());
      EXPECT_THROW(*ptr, std::exception);
      EXPECT_THROW(ptr.ToObject(), std::exception);
    }
  }
  
  TEST(Sp, SetNotNull) {
    TestPointer::ResetCpt();
    pcf_using(refptr<TestPointer> ptr(new TestPointer())) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_NO_THROW(*ptr);
      EXPECT_NO_THROW(ptr.ToObject());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(Sp, Set) {
    TestPointer::ResetCpt();
    TestPointer* tp = new TestPointer();
    EXPECT_EQ(1, TestPointer::GetCpt());
    pcf_using(refptr<TestPointer> ptr(tp)) {
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_NO_THROW(*ptr);
      EXPECT_NO_THROW(ptr.ToObject());
      EXPECT_EQ(tp, ptr.ToPointer());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(Sp, SetFromEqual) {
    TestPointer::ResetCpt();
    pcf_using(refptr<TestPointer> ptr = new TestPointer()) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_NE((TestPointer*)null, ptr.ToPointer());
      EXPECT_FALSE(ptr.IsNull());
      EXPECT_NO_THROW(*ptr);
      EXPECT_NO_THROW(ptr.ToObject());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(Sp, SetFromSharedPointer) {
    TestPointer::ResetCpt();
    pcf_using(refptr<TestPointer> ptr1(new TestPointer())) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      pcf_using(refptr<TestPointer> ptr2(ptr1)) {
        EXPECT_EQ(1, TestPointer::GetCpt());
        EXPECT_EQ(2, ptr1.GetUseCount());
        EXPECT_EQ(2, ptr2.GetUseCount());
        EXPECT_NE((TestPointer*)null, ptr1.ToPointer());
        EXPECT_NE((TestPointer*)null, ptr2.ToPointer());
        EXPECT_TRUE(ptr1 == ptr2);
        EXPECT_FALSE(ptr1.IsNull());
        EXPECT_FALSE(ptr2.IsNull());
        EXPECT_NO_THROW(*ptr2);
        EXPECT_NO_THROW(ptr2.ToObject());
        EXPECT_EQ("TestPointer", ptr2.ToObject().ToString());
      }
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_EQ(1, ptr1.GetUseCount());
      EXPECT_EQ("TestPointer", ptr1.ToObject().ToString());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(Sp, SetFromEqualSharedPointer) {
    TestPointer::ResetCpt();
    pcf_using(refptr<TestPointer> ptr1(new TestPointer())) {
      EXPECT_EQ(1, TestPointer::GetCpt());
      pcf_using(refptr<TestPointer> ptr2 = ptr1) {
        EXPECT_EQ(1, TestPointer::GetCpt());
        EXPECT_EQ(2, ptr1.GetUseCount());
        EXPECT_EQ(2, ptr2.GetUseCount());
        EXPECT_NE((TestPointer*)null, ptr1.ToPointer());
        EXPECT_NE((TestPointer*)null, ptr2.ToPointer());
        EXPECT_TRUE(ptr1 == ptr2);
        EXPECT_FALSE(ptr1.IsNull());
        EXPECT_FALSE(ptr2.IsNull());
        EXPECT_NO_THROW(*ptr2);
        EXPECT_NO_THROW(ptr2.ToObject());
        EXPECT_EQ("TestPointer", ptr2.ToObject().ToString());
      }
      EXPECT_EQ(1, TestPointer::GetCpt());
      EXPECT_EQ(1, ptr1.GetUseCount());
      EXPECT_EQ("TestPointer", ptr1.ToObject().ToString());
    }
    EXPECT_EQ(0, TestPointer::GetCpt());
  }
  
  TEST(Sp, Constructor) {
    refptr<string> stringEmpty;
    EXPECT_TRUE(stringEmpty.IsNull());
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(stringEmpty));
    EXPECT_THROW(stringEmpty.ToObject(), std::exception);
    EXPECT_THROW(stringEmpty.ToPointer(), std::exception);
    EXPECT_EQ(0, stringEmpty.GetUseCount());
    EXPECT_THROW(*stringEmpty, std::exception);
    EXPECT_THROW(stringEmpty->Length(), std::exception);
    EXPECT_THROW((*stringEmpty)[0], std::exception);
    
    refptr<string> stringEmpty2(refptr<string>::Empty());
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(stringEmpty2));
    EXPECT_THROW(stringEmpty2.ToObject(), std::exception);
    EXPECT_THROW(stringEmpty2.ToPointer(), std::exception);
    EXPECT_EQ(0, stringEmpty2.GetUseCount());
    EXPECT_THROW(*stringEmpty2, std::exception);
    EXPECT_THROW(stringEmpty2->Length(), std::exception);
    EXPECT_THROW((*stringEmpty2)[0], std::exception);
    
    refptr<string> stringNull(null);
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(stringNull));
    EXPECT_THROW(stringNull.ToObject(), std::exception);
    EXPECT_THROW(stringNull.ToPointer(), std::exception);
    EXPECT_EQ(0, stringNull.GetUseCount());
    EXPECT_THROW(*stringNull, std::exception);
    EXPECT_THROW(stringNull->Length(), std::exception);
    EXPECT_THROW((*stringNull)[0], std::exception);
    
    refptr<string> str(new string("Test Share Pointer"));
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("Test Share Pointer", str.ToObject());
    EXPECT_EQ("Test Share Pointer", *str.ToPointer());
    EXPECT_EQ(1, str.GetUseCount());
    EXPECT_EQ("Test Share Pointer", *str);
    EXPECT_EQ(18,str->Length());
    EXPECT_EQ('T', (*str)[0]);
    
    refptr<string> str2= new string("Test an other Share Pointer");
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str2));
    EXPECT_EQ("Test an other Share Pointer", str2.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str2.ToPointer());
    EXPECT_EQ(1, str2.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str2);
    EXPECT_EQ(27, str2->Length());
    EXPECT_EQ('T', (*str2)[0]);
    
    refptr<string> str3(str);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("Test Share Pointer", str.ToObject());
    EXPECT_EQ("Test Share Pointer", *str.ToPointer());
    EXPECT_EQ(2, str.GetUseCount());
    EXPECT_EQ(*str, "Test Share Pointer");
    EXPECT_EQ(18, str->Length());
    EXPECT_EQ('T', (*str)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test Share Pointer", str3.ToObject());
    EXPECT_EQ("Test Share Pointer", *str3.ToPointer());
    EXPECT_EQ(2, str3.GetUseCount());
    EXPECT_EQ("Test Share Pointer", *str3);
    EXPECT_EQ(18, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
  }
  
  TEST(Sp, Equal) {
    refptr<string> stringEmpty = refptr<string>::Empty();
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(stringEmpty));
    EXPECT_THROW(stringEmpty.ToObject(), std::exception);
    EXPECT_THROW(stringEmpty.ToPointer(), std::exception);
    EXPECT_EQ(0, stringEmpty.GetUseCount());
    EXPECT_THROW(*stringEmpty, std::exception);
    EXPECT_THROW(stringEmpty->Length(), std::exception);
    EXPECT_THROW((*stringEmpty)[0], std::exception);
    
    refptr<string> stringNull = refptr<String>::Null();
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(stringNull));
    EXPECT_THROW(stringNull.ToObject(), std::exception);
    EXPECT_THROW(stringNull.ToPointer(), std::exception);
    EXPECT_EQ(0, stringNull.GetUseCount());
    EXPECT_THROW(*stringNull, std::exception);
    EXPECT_THROW(stringNull->Length(), std::exception);
    EXPECT_THROW((*stringNull)[0], std::exception);
    
    refptr<string> str =new string("Test Share Pointer");
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("Test Share Pointer", str.ToObject());
    EXPECT_EQ("Test Share Pointer", *str.ToPointer());
    EXPECT_EQ(1, str.GetUseCount());
    EXPECT_EQ("Test Share Pointer", *str);
    EXPECT_EQ(18,str->Length());
    EXPECT_EQ('T', (*str)[0]);
    
    refptr<string> str2 =new string("Test an other Share Pointer");
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str2));
    EXPECT_EQ("Test an other Share Pointer", str2.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str2.ToPointer());
    EXPECT_EQ(1, str2.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str2);
    EXPECT_EQ(27, str2->Length());
    EXPECT_EQ('T', (*str2)[0]);
    
    refptr<string> str3 = str;
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("Test Share Pointer", str.ToObject());
    EXPECT_EQ("Test Share Pointer", *str.ToPointer());
    EXPECT_EQ(2, str.GetUseCount());
    EXPECT_EQ("Test Share Pointer", *str);
    EXPECT_EQ(18,str->Length());
    EXPECT_EQ('T', (*str)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test Share Pointer", str3.ToObject());
    EXPECT_EQ("Test Share Pointer", *str3.ToPointer());
    EXPECT_EQ(2, str3.GetUseCount());
    EXPECT_EQ("Test Share Pointer", *str3);
    EXPECT_EQ(18,str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    EXPECT_EQ(2, str.GetUseCount());
    
    *str = "This is a new Value for the Share Pointer";
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("This is a new Value for the Share Pointer", str.ToObject());
    EXPECT_EQ("This is a new Value for the Share Pointer", *str.ToPointer());
    EXPECT_EQ(2, str.GetUseCount());
    EXPECT_EQ("This is a new Value for the Share Pointer", *str);
    EXPECT_EQ(41, str->Length());
    EXPECT_EQ('T', (*str)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("This is a new Value for the Share Pointer", str3.ToObject());
    EXPECT_EQ("This is a new Value for the Share Pointer", *str3.ToPointer());
    EXPECT_EQ(2, str3.GetUseCount());
    EXPECT_EQ("This is a new Value for the Share Pointer", *str3);
    EXPECT_EQ(41, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    EXPECT_EQ(2, str.GetUseCount());
    
    *str3 = "And an other one";
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("And an other one", str.ToObject());
    EXPECT_EQ("And an other one", *str.ToPointer());
    EXPECT_EQ(2, str.GetUseCount());
    EXPECT_EQ("And an other one", *str);
    EXPECT_EQ(16, str->Length());
    EXPECT_EQ('A', (*str)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("And an other one", str3.ToObject());
    EXPECT_EQ("And an other one", *str3.ToPointer());
    EXPECT_EQ(2, str3.GetUseCount());
    EXPECT_EQ("And an other one", *str3);
    EXPECT_EQ(16, str3->Length());
    EXPECT_EQ('A', (*str3)[0]);
    EXPECT_EQ(2, str.GetUseCount());
    
    str3 = str2;
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("And an other one", str.ToObject());
    EXPECT_EQ("And an other one", *str.ToPointer());
    EXPECT_EQ(1, str.GetUseCount());
    EXPECT_EQ("And an other one", *str);
    EXPECT_EQ(16, str->Length());
    EXPECT_EQ('A', (*str)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str2));
    EXPECT_EQ("Test an other Share Pointer", str2.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str2.ToPointer());
    EXPECT_EQ(2, str2.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str2);
    EXPECT_EQ(27, str2->Length());
    EXPECT_EQ('T', (*str2)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test an other Share Pointer", str3.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str3.ToPointer());
    EXPECT_EQ(2, str3.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str3);
    EXPECT_EQ(27, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    
    str2 = refptr<string>::Null();
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str));
    EXPECT_EQ("And an other one", str.ToObject());
    EXPECT_EQ("And an other one", *str.ToPointer());
    EXPECT_EQ(1, str.GetUseCount());
    EXPECT_EQ("And an other one", *str);
    EXPECT_EQ(16, str->Length());
    EXPECT_EQ('A', (*str)[0]);
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(str2));
    EXPECT_THROW(str2.ToObject(), std::exception);
    EXPECT_THROW(str2.ToPointer(), std::exception);
    EXPECT_EQ(0, str2.GetUseCount());
    EXPECT_THROW(*str2, std::exception);
    EXPECT_THROW(str2->Length(), std::exception);
    EXPECT_THROW((*str2)[0], std::exception);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test an other Share Pointer", str3.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str3.ToPointer());
    EXPECT_EQ(1, str3.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str3);
    EXPECT_EQ(27, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    
    refptr<string> str4 = str3;
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test an other Share Pointer", str3.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str3.ToPointer());
    EXPECT_EQ(2, str3.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str3);
    EXPECT_EQ(27, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str4));
    EXPECT_EQ("Test an other Share Pointer", str4.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str4.ToPointer());
    EXPECT_EQ(2, str4.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str4);
    EXPECT_EQ(27, str4->Length());
    EXPECT_EQ('T', (*str4)[0]);
    
    str4 = refptr<string>::Empty();
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test an other Share Pointer", str3.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str3.ToPointer());
    EXPECT_EQ(1, str3.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str3);
    EXPECT_EQ(27, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    EXPECT_TRUE(refptr<string>::IsNullOrInvalid(str4));
    EXPECT_THROW(str4.ToObject(), std::exception);
    EXPECT_THROW(str4.ToPointer(), std::exception);
    EXPECT_EQ(0, str4.GetUseCount());
    EXPECT_THROW(*str4, std::exception);
    EXPECT_THROW(str4->Length(), std::exception);
    EXPECT_THROW((*str4)[0], std::exception);
    
    refptr<string> str5 = str3;
    refptr<string> str6 = str5;
    refptr<string> str7 = str3;
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str3));
    EXPECT_EQ("Test an other Share Pointer", str3.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str3.ToPointer());
    EXPECT_EQ(4, str3.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str3);
    EXPECT_EQ(27, str3->Length());
    EXPECT_EQ('T', (*str3)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str5));
    EXPECT_EQ("Test an other Share Pointer", str5.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str5.ToPointer());
    EXPECT_EQ(str5.GetUseCount(), 4);
    EXPECT_EQ("Test an other Share Pointer", *str5);
    EXPECT_EQ(27, str5->Length());
    EXPECT_EQ('T', (*str5)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str6));
    EXPECT_EQ("Test an other Share Pointer", str6.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str6.ToPointer());
    EXPECT_EQ(4, str6.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str6);
    EXPECT_EQ(27, str6->Length());
    EXPECT_EQ('T', (*str6)[0]);
    EXPECT_FALSE(refptr<string>::IsNullOrInvalid(str7));
    EXPECT_EQ("Test an other Share Pointer", str7.ToObject());
    EXPECT_EQ("Test an other Share Pointer", *str7.ToPointer());
    EXPECT_EQ(4, str7.GetUseCount());
    EXPECT_EQ("Test an other Share Pointer", *str7);
    EXPECT_EQ(27, str7->Length());
    EXPECT_EQ('T', (*str7)[0]);
  }
  
  TEST(Sp, Null) {
    /*
     refptr<string> stringNull;
     EXPECT_TRUE(stringNull == IntPtr::Zero);
     EXPECT_TRUE(stringNull == IntPtr(null));
     EXPECT_TRUE(!stringNull);
     EXPECT_FALSE(stringNull != IntPtr::Zero);
     EXPECT_FALSE(stringNull != IntPtr(null));
     EXPECT_FALSE(stringNull);
     
     refptr<string> str =new string();
     EXPECT_FALSE(str == IntPtr::Zero);
     EXPECT_FALSE(str == IntPtr(null));
     EXPECT_FALSE(!str);
     EXPECT_TRUE(str != IntPtr::Zero);
     EXPECT_TRUE(str != IntPtr(null));
     EXPECT_TRUE(str);
     */
  }
  
  TEST(Sp, Cast) {
    refptr<string> str= new string("Test for cast");
    string strCopy;
    
    EXPECT_EQ("Test for cast", *str);
    strCopy = *str;
    EXPECT_EQ("Test for cast", strCopy);
  }
  
  TEST(Sp, Release) {
    ParentA::parentAReleaseCount=0;
    {
      refptr<ParentA> parentA=new ParentA();
      refptr<ParentA> parentA1=new ParentA();
      EXPECT_EQ(0, ParentA::parentAReleaseCount);
    }
    EXPECT_EQ(2, ParentA::parentAReleaseCount);
  }
  
  TEST(Sp, Copy) {
    ParentA::parentAReleaseCount=0;
    {
      refptr<ParentA> parentA=new ParentA();
      refptr<ParentA> parentA1(parentA);
      EXPECT_EQ(0, ParentA::parentAReleaseCount);
    }
    EXPECT_EQ(1, ParentA::parentAReleaseCount);
  }
  
  TEST(Sp, Affectation) {
    ParentA::parentAReleaseCount=0;
    {
      refptr<ParentA> parentA=new ParentA();
      refptr<ParentA> parentA1=parentA;
      EXPECT_EQ(0, ParentA::parentAReleaseCount);
    }
    EXPECT_EQ(1, ParentA::parentAReleaseCount);
  }
  
  TEST(Sp, Cast2) {
    ParentA::parentAReleaseCount=0;
    ChildB::childBReleaseCount=0;
    {
      refptr<ChildB> childB=new ChildB();
      refptr<ParentA> parentA = childB.ChangeType<ParentA>();
      EXPECT_EQ(0, ParentA::parentAReleaseCount);
      EXPECT_EQ(0, ChildB::childBReleaseCount);
    }
    EXPECT_EQ(1, ParentA::parentAReleaseCount);
    EXPECT_EQ(1, ChildB::childBReleaseCount);
  }
  
  TEST(Sp, ToObjectTT) {
    refptr<string> spString(new string("Hello World"));
    refptr<Object> obj = spString.ChangeType<Object>();
    string str = obj.ToObject<string>();
    EXPECT_TRUE(str.Equals("Hello World"));
    EXPECT_THROW(obj.ToObject<Int32>(), std::exception);
  }
  
  TEST(Sp, ToPointerTT) {
    refptr<string> spString(new string("Hello World"));
    refptr<Object> obj = spString.ChangeType<Object>();
    string* str = obj.ToPointer<string>();
    EXPECT_TRUE(str->Equals("Hello World"));
  }
  
  TEST(Sp, Equality) {
    Switch::refptr<std::string> s1 = new std::string("string 1");
  }
  
  TEST(Sp, CopyCast) {
    ParentA::parentAReleaseCount=0;
    ChildB::childBReleaseCount=0;
    {
      refptr<ChildB> childB=new ChildB();
      //refptr<ParentA> parentA(childB);
      refptr<ParentA> parentA = childB.ChangeType<ParentA>();
      
      EXPECT_EQ(0, ParentA::parentAReleaseCount);
      EXPECT_EQ(0, ChildB::childBReleaseCount);
    }
    EXPECT_EQ(1, ParentA::parentAReleaseCount);
    EXPECT_EQ(1, ChildB::childBReleaseCount);
  }
  
}
