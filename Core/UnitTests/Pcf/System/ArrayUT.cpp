#include <Pcf/System/Array.h>
#include <Pcf/TUnit/Assert.h>
#include <Pcf/TUnit/TestFixture.h>

using namespace System;
using namespace TUnit;

namespace PcfUnitTests {
  class ArrayTest : public TestFixture {
  protected:
    
    void ConstructorEmpty() {
      Array<int32> a;
      Assert::AreEqual(a.Length, 0, pcf_current_information);
    }
    
    void Length() {
      Array<int32> a;
      Assert::AreEqual(a.Length, 0, pcf_current_information);
    }
    
    void AccessExceptions() {
      Array<int32> a;
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[-1];}, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a[0];}, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a(0);}, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a(-1);}, pcf_current_information);
    }
    
    void ConstructorFromNative() {
      int32 a2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
      Array<int32> a3(a2);
      Assert::AreEqual(a3.Length, 9, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a3[-1];}, pcf_current_information);
      Assert::AreEqual(10, a3[0], pcf_current_information);
      Assert::AreEqual(20, a3[1], pcf_current_information);
      Assert::AreEqual(30, a3[2], pcf_current_information);
      Assert::AreEqual(40, a3[3], pcf_current_information);
      Assert::AreEqual(50, a3[4], pcf_current_information);
      Assert::AreEqual(60, a3[5], pcf_current_information);
      Assert::AreEqual(70, a3[6], pcf_current_information);
      Assert::AreEqual(80, a3[7], pcf_current_information);
      Assert::AreEqual(90, a3[8], pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a3[9];}, pcf_current_information);
      
      Array<int32> a4(5);
      a4[2] = 3;
      a4[4] = 5;
      Assert::AreEqual(a4.Length, 5);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a4[-1];}, pcf_current_information);
      Assert::AreEqual(a4[0], 0, pcf_current_information);
      Assert::AreEqual(a4[1], 0, pcf_current_information);
      Assert::AreEqual(a4[2], 3, pcf_current_information);
      Assert::AreEqual(a4[3], 0, pcf_current_information);
      Assert::AreEqual(a4[4], 5, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a4[5];}, pcf_current_information);
      
      Array<int32> a6(5);
      a6[2] = 3;
      Assert::AreEqual(a6[2], 3, pcf_current_information);
      a6(4) = 50;
      Assert::AreEqual(a6(4), 50, pcf_current_information);
      
      Array<int32> a8(10);
      for (int32 i = 0; i < 10; i++)
        a8(i) = i;
      for (int32 i = 0; i < 10; i++)
        Assert::AreEqual(a8(i), i, pcf_current_information);
      
      int32 a11[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
      Array<int32> a12(a11, 3);
      Assert::AreEqual(a12.Length, 3, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a12[-1];}, pcf_current_information);
      Assert::AreEqual(a12[0], 100, pcf_current_information);
      Assert::AreEqual(a12[1], 200, pcf_current_information);
      Assert::AreEqual(a12[2], 300, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a12[3];}, pcf_current_information);
      
      Array<int32> a13(a12);
      Assert::AreEqual(a13.Length, a12.Length, pcf_current_information);
    }
    
    void ConstructorFromInitializerList() {
      Array<int32> a3 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
      Assert::AreEqual(a3.Length, 9, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a3[-1];}, pcf_current_information);
      Assert::AreEqual(a3[0], 10, pcf_current_information);
      Assert::AreEqual(a3[1], 20, pcf_current_information);
      Assert::AreEqual(a3[2], 30, pcf_current_information);
      Assert::AreEqual(a3[3], 40, pcf_current_information);
      Assert::AreEqual(a3[4], 50, pcf_current_information);
      Assert::AreEqual(a3[5], 60, pcf_current_information);
      Assert::AreEqual(a3[6], 70, pcf_current_information);
      Assert::AreEqual(a3[7], 80, pcf_current_information);
      Assert::AreEqual(a3[8], 90, pcf_current_information);
      Assert::Throws<ArgumentOutOfRangeException>(pcf_delegate {a3[9];}, pcf_current_information);
    }
    
  };
  
  pcf_test(ArrayTest, ConstructorEmpty)
  pcf_test(ArrayTest, Length)
  pcf_test(ArrayTest, AccessExceptions)
  pcf_test(ArrayTest, ConstructorFromNative)
  pcf_test(ArrayTest, ConstructorFromInitializerList)
  
  
  class MyType : public System::Object {
  public:
    static int32 initCounter;
    static int32 copyCounter;
    
    MyType() {initCounter += 1;}
    
    MyType(const MyType&) {copyCounter += 1;}
    
    MyType& operator =(const MyType&) {return *this;}
  };
  
  int32 MyType::initCounter = 0;
  int32 MyType::copyCounter = 0;
  
  TEST(Array, ConstructorAndTDefConstructor) {
    MyType::initCounter = 0;
    MyType::copyCounter = 0;
    
    Array<MyType> array;
    Assert::AreEqual(0,MyType::copyCounter);
    
    Array<MyType> array2(10);
    
    EXPECT_EQ(10, MyType::initCounter);
    EXPECT_EQ(0, MyType::copyCounter);
    
    array2.Resize(12);
    EXPECT_LE(12, MyType::initCounter);
    EXPECT_LE(12, MyType::copyCounter);
    
    array2.Resize(5);
    EXPECT_LE(12, MyType::initCounter);
    EXPECT_LE(12, MyType::copyCounter);
  }
  
  TEST(Array, ConstructorFromList) {
    Collections::Generic::List<Int32> List;
    List.Add(Int32(0));
    List.Add(Int32(1));
    
    Array<Int32> arrayFromList(List);
    Assert::AreEqual(List.Count, arrayFromList.Length);
  }
  
  TEST(Array, ConstructorFromVarArgs) {
    Array<Int32, 2> a7(10, 8);
    a7(0, 0) = 24;
    a7(8, 5) = 3;
    Assert::AreEqual(a7(0, 0), 24);
    Assert::AreEqual(a7(8, 5), 3);
    EXPECT_THROW(a7(4, 10), IndexOutOfRangeException);
    EXPECT_THROW(a7(15, 5), IndexOutOfRangeException);
    
    Array<Int32, 2> a9(10, 8);
    for (Int32 i = 0; i < 10; i++)
      for (Int32 j = 0; j < 8; j++)
        a9(i, j) = (i*10) + j;
    
    for (Int32 i = 0; i < 10; i++)
      for (Int32 j = 0; j < 8; j++)
        Assert::AreEqual(a9(i, j), (i*10) + j);
    
    Array<Int32, 3> a10(10, 10, 10);
    for (Int32 i = 0; i < 10; i++)
      for (Int32 j = 0; j < 10; j++)
        for (Int32 k = 0; k < 10; k++)
          a10(i, j, k) = (i*100) + (j*10) + k;
    
    for (Int32 i = 0; i < 10; i++)
      for (Int32 j = 0; j < 10; j++)
        for (Int32 k = 0; k < 10; k++)
          Assert::AreEqual(a10(i, j, k), (i*100) + (j*10) + k);
  }
  
  TEST(Array, Resize) {
    Array<Int32> a1;
    Assert::AreEqual(a1.Length, 0);
    EXPECT_THROW(a1[-1], ArgumentOutOfRangeException);
    EXPECT_THROW(a1[0], ArgumentOutOfRangeException);
    
    Array<Int32>::Resize(a1, 1);
    Assert::AreEqual(a1.Length, 1);
    Assert::AreEqual(a1[0], 0);
    EXPECT_THROW(a1[1], ArgumentOutOfRangeException);
    
    Array<Int32>::Resize(a1, 10);
    Assert::AreEqual(a1.Length, 10);
    Assert::AreEqual(a1[9], 0);
    EXPECT_THROW(a1[10], ArgumentOutOfRangeException);
    
    Array<Int32>::Resize(a1, 5);
    Assert::AreEqual(a1.Length, 5);
    Assert::AreEqual(a1[4], 0);
    EXPECT_THROW(a1[5], ArgumentOutOfRangeException);
    
    // No Resize for an Array
    Array<string, 2> a2(Int32(0), Int32(0));
    Assert::AreEqual(a2.Length, 0);
    EXPECT_THROW((Array<string, 2>::Resize(a2, 10)), ArgumentException);
    
    Int32 a3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Array<Int32> a4(a3, 0);
    EXPECT_THROW(a4[0], ArgumentOutOfRangeException);
    
    Array<Int32>::Resize(a4, 3);
    Assert::AreEqual(a4.Length, 3);
    Assert::AreEqual(a4[2], 0);
    EXPECT_THROW(a4[4], ArgumentOutOfRangeException);
    Array<Int32>::Resize(a4, 2);
    EXPECT_THROW(a4[2], ArgumentOutOfRangeException);
    
    Array<Int32>::Resize(a4, 6);
    Assert::AreEqual(a4.Length, 6);
    Assert::AreEqual(a4[5], 0);
    EXPECT_THROW(a4[6], ArgumentOutOfRangeException);
    
    Array<Int32>::Resize(a4, 10);
    Assert::AreEqual(a4.Length, 10);
  }
  
  TEST(Array, AssignementOperator) {
    Array<string> a1(5);
    a1[0] = "Tyrannosaurus";
    a1[1] = "Compsognathus";
    a1[2] = "Amargasaurus";
    a1[3] = "Oviraptor";
    a1[4] = "Velociraptor";
    
    Assert::IsTrue(a1[0] == "Tyrannosaurus");
    Assert::IsTrue(a1[1] == "Compsognathus");
    Assert::IsTrue(a1[2] == "Amargasaurus");
    Assert::IsTrue(a1[3] == "Oviraptor");
    Assert::IsTrue(a1[4] == "Velociraptor");
    
    Array<string> a2(5);
    a2 = a1;
    Assert::AreEqual(a2[0], a1[0]);
    Assert::AreEqual(a2[1], a1[1]);
    Assert::AreEqual(a2[2], a1[2]);
    Assert::AreEqual(a2[3], a1[3]);
    Assert::AreEqual(a2[4], a1[4]);
    
    Array<string> a3;
    a3 = a2;
    Assert::AreEqual(a3.Length, 5);
  }
  
  TEST(Array, CopyTo) {
    Array<string> a1(5);
    a1[0] = "Tyrannosaurus";
    a1[1] = "Compsognathus";
    a1[2] = "Amargasaurus";
    a1[3] = "Oviraptor";
    a1[4] = "Velociraptor";
    
    Array<string> a2(9);
    a2[0] = "Test1";
    a2[1] = "Test2";
    a2[2] = "Test3";
    a2[8] = "Test8";
    
    a1.CopyTo(a2, 3);
    Assert::AreEqual(a2[3], a1[0]);
    Assert::AreEqual(a2[4], a1[1]);
    Assert::AreEqual(a2[5], a1[2]);
    Assert::AreEqual(a2[6], a1[3]);
    Assert::AreEqual(a2[7], a1[4]);
  }
  
  TEST(Array, StaticArray) {
    Array<string> array1 = {"1", "2", "3", "4", "5"};
    Array<string> array2 = {"1", "2", "3", "4", "5"};
    
    array1[0] = "Test1";
    array1[1] = "Test2";
    array1[2] = "Test3";
    array1[3] = "Test4";
    array1[4] = "Test5";
    
    array2 = array1;
    
    Assert::AreEqual(array1[3],string("Test4"));
    Assert::AreEqual(array2[3],string("Test4"));
    
    Collections::Generic::Enumerator<string> enum1 = array1.GetEnumerator();
    Collections::Generic::Enumerator<string> enum2 = array2.GetEnumerator();
    while (enum1.MoveNext() && enum2.MoveNext())
      Assert::AreEqual(enum1.Current(), enum2.Current());
    
    array1[3] = "Reset";
    
    Assert::AreEqual(array1[3], string("Reset"));
    EXPECT_NE(array2[3], string("Reset"));
    
    Array<string>::Resize(array1, 3);
    Assert::AreEqual(array1.Length, 3);
    Array<string>::Resize(array1,6);
    Assert::AreEqual(array1.Length, 6);
  }
  
  
  TEST(Array, PolymorphicArray) {
    Array<refptr<Object>> PolymorphicList(50);
    PolymorphicList[0] = pcf_new<Int32>(1024);
    PolymorphicList[1] = pcf_new<String>("Polymorphic");
    PolymorphicList[2] = pcf_new<Boolean>(true);
    PolymorphicList[3] = pcf_new<Char>('P');
    
    Assert::IsTrue(is<Int32>(*(PolymorphicList[0])));
    Assert::IsTrue(is<string>(*(PolymorphicList[1])));
    Assert::IsTrue(is<Boolean>(*(PolymorphicList[2])));
    Assert::IsTrue(is<Char>(*(PolymorphicList[3])));
    
    Assert::AreEqual(string("1024"), PolymorphicList[0]->ToString());
    Assert::AreEqual(string("Polymorphic"), PolymorphicList[1]->ToString());
    Assert::AreEqual(string("True"), PolymorphicList[2]->ToString());
    Assert::AreEqual(string("P"), PolymorphicList[3]->ToString());
  }
  
  TEST(Array, GetEnumerator) {
    Array<int32> array(10);
    for (int32 i = 0; i < 10; i++)
      array[i] = (i+10)*2;
    
    pcf_using(System::Collections::Generic::Enumerator<int32> enumerator = array.GetEnumerator()) {
      int32 index = 0;
      while (enumerator.MoveNext()) {
        Assert::AreEqual((index+10)*2, enumerator.Current);
        index++;
      }
    }
  }
}