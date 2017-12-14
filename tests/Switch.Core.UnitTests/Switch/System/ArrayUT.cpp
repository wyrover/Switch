#include <Switch/System/Array.hpp>
#include <Switch/System/Char.hpp>
#include <Switch/Using.hpp>
#include <gtest/gtest.h>

using namespace System;

namespace SwitchUnitTests {
  TEST(ArrayTest, CreateOneDimensionalArrayWithCreateInstance) {
    ASSERT_EQ(1, Array<>::CreateInstance<int>(3).Rank);
    ASSERT_EQ(3, Array<>::CreateInstance<int>(3).Length);
  }

  TEST(ArrayTest, CreateOneDimensionalArrayWithCreateInstanceWithLengthArraySpecified) {
    ASSERT_EQ(1, (Array<>::CreateInstance<int, 1>({3}).Rank));
    ASSERT_EQ(3, (Array<>::CreateInstance<int, 1>({3}).Length));
  }

  TEST(ArrayTest, CreateTwoDimensionalArrayWithCreateInstance) {
    ASSERT_EQ(2, (Array<>::CreateInstance<int>(3, 5).Rank));
    ASSERT_EQ(15, (Array<>::CreateInstance<int>(3, 5).Length));
  }

  TEST(ArrayTest, CreateTwoDimensionalArrayWithCreateInstanceWithLengthArraySpecified) {
    ASSERT_EQ(2, (Array<>::CreateInstance<int, 2>({3, 5}).Rank));
    ASSERT_EQ(15, (Array<>::CreateInstance<int, 2>({3, 5}).Length));
  }

  TEST(ArrayTest, CreateThreeDimensionalArrayWithCreateInstance) {
    ASSERT_EQ(3, Array<>::CreateInstance<int>(3, 5, 2).Rank);
    ASSERT_EQ(30, Array<>::CreateInstance<int>(3, 5, 2).Length);
  }

  TEST(ArrayTest, CreateThreeDimensionalArrayWithCreateInstanceWithLengthArraySpecified) {
    ASSERT_EQ(3, (Array<>::CreateInstance<int, 3>({3, 5, 2}).Rank));
    ASSERT_EQ(30, (Array<>::CreateInstance<int, 3>({3, 5, 2}).Length));
  }

  TEST(ArrayTest, CreateFourDimensionalArrayWithCreateInstance) {
    ASSERT_EQ(4, (Array<>::CreateInstance<int, 4>({3, 5, 2, 4}).Rank));
    ASSERT_EQ(120, (Array<>::CreateInstance<int, 4>({3, 5, 2, 4}).Length));
  }

  TEST(ArrayTest, ConstructorEmpty) {
    Array<int32> a;
    ASSERT_EQ(a.Length, 0);
  }

  TEST(ArrayTest, Length) {
    Array<int32> a;
    ASSERT_EQ(a.Length, 0);
  }

  TEST(ArrayTest, AccessExceptions) {
    Array<int32> a;
    ASSERT_THROW(a[-1], ArgumentOutOfRangeException);
    ASSERT_THROW(a[0], ArgumentOutOfRangeException);
    ASSERT_THROW(a(0), ArgumentOutOfRangeException);
    ASSERT_THROW(a(-1), ArgumentOutOfRangeException);
  }

  TEST(ArrayTest, ConstructorFromNative) {
    int32 a2[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    Array<int32> a3(a2);
    ASSERT_EQ(a3.Length, 9);
    ASSERT_THROW(a3[-1], ArgumentOutOfRangeException);
    ASSERT_EQ(10, a3[0]);
    ASSERT_EQ(20, a3[1]);
    ASSERT_EQ(30, a3[2]);
    ASSERT_EQ(40, a3[3]);
    ASSERT_EQ(50, a3[4]);
    ASSERT_EQ(60, a3[5]);
    ASSERT_EQ(70, a3[6]);
    ASSERT_EQ(80, a3[7]);
    ASSERT_EQ(90, a3[8]);
    ASSERT_THROW(a3[9], ArgumentOutOfRangeException);

    Array<int32> a4(5);
    a4[2] = 3;
    a4[4] = 5;
    ASSERT_EQ(a4.Length, 5);
    ASSERT_THROW(a4[-1], ArgumentOutOfRangeException);
    ASSERT_EQ(a4[0], 0);
    ASSERT_EQ(a4[1], 0);
    ASSERT_EQ(a4[2], 3);
    ASSERT_EQ(a4[3], 0);
    ASSERT_EQ(a4[4], 5);
    ASSERT_THROW(a4[5], ArgumentOutOfRangeException);

    Array<int32> a6(5);
    a6[2] = 3;
    ASSERT_EQ(a6[2], 3);
    a6(4) = 50;
    ASSERT_EQ(a6(4), 50);

    Array<int32> a8(10);
    for (int32 index = 0; index < 10; index++)
      a8(index) = index;
    for (int32 index = 0; index < 10; index++)
      ASSERT_EQ(a8(index), index);

    int32 a11[] = {100, 200, 300, 400, 500, 600, 700, 800, 900};
    Array<int32> a12(a11, 3);
    ASSERT_EQ(a12.Length, 3);
    ASSERT_THROW(a12[-1], ArgumentOutOfRangeException);
    ASSERT_EQ(a12[0], 100);
    ASSERT_EQ(a12[1], 200);
    ASSERT_EQ(a12[2], 300);
    ASSERT_THROW(a12[3], ArgumentOutOfRangeException);

    Array<int32> a13(a12);
    ASSERT_EQ(a13.Length, a12.Length);
  }

  TEST(ArrayTest, ConstructorFromInitializerList) {
    Array<int32> a3 = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    ASSERT_EQ(a3.Length, 9);
    ASSERT_THROW(a3[-1], ArgumentOutOfRangeException);
    ASSERT_EQ(a3[0], 10);
    ASSERT_EQ(a3[1], 20);
    ASSERT_EQ(a3[2], 30);
    ASSERT_EQ(a3[3], 40);
    ASSERT_EQ(a3[4], 50);
    ASSERT_EQ(a3[5], 60);
    ASSERT_EQ(a3[6], 70);
    ASSERT_EQ(a3[7], 80);
    ASSERT_EQ(a3[8], 90);
    ASSERT_THROW(a3[9], ArgumentOutOfRangeException);
  }

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
    ASSERT_EQ(0, MyType::copyCounter);

    Array<MyType> array2(10);

    ASSERT_EQ(10, MyType::initCounter);
    ASSERT_EQ(0, MyType::copyCounter);

    Array<>::Resize(array2, 12);
    EXPECT_LE(12, MyType::initCounter);
    EXPECT_LE(12, MyType::copyCounter);

    Array<>::Resize(array2, 5);
    EXPECT_LE(12, MyType::initCounter);
    EXPECT_LE(12, MyType::copyCounter);
  }

  TEST(Array, ConstructorFromList) {
    Collections::Generic::List<Int32> List;
    List.Add(Int32(0));
    List.Add(Int32(1));

    Array<Int32> arrayFromList(List);
    ASSERT_EQ(List.Count, arrayFromList.Length);
  }

  TEST(Array, ConstructorFromVarArgs) {
    Array<Int32, 2> a7(10, 8);
    a7(0, 0) = 24;
    a7(8, 5) = 3;
    ASSERT_EQ(a7(0, 0), 24);
    ASSERT_EQ(a7(8, 5), 3);
    ASSERT_THROW(a7(4, 10), IndexOutOfRangeException);
    ASSERT_THROW(a7(15, 5), IndexOutOfRangeException);

    Array<Int32, 2> a9(10, 8);
    for (Int32 index1 = 0; index1 < 10; index1++)
      for (Int32 index2 = 0; index2 < 8; index2++)
        a9(index1, index2) = (index1 * 10) + index2;

    for (Int32 index1 = 0; index1 < 10; index1++)
      for (Int32 index2 = 0; index2 < 8; index2++)
        ASSERT_EQ(a9(index1, index2), (index1 * 10) + index2);

    Array<Int32, 3> a10(10, 10, 10);
    for (Int32 index1 = 0; index1 < 10; index1++)
      for (Int32 index2 = 0; index2 < 10; index2++)
        for (Int32 index3 = 0; index3 < 10; index3++)
          a10(index1, index2, index3) = (index1 * 100) + (index2 * 10) + index3;

    for (Int32 index1 = 0; index1 < 10; index1++)
      for (Int32 index2 = 0; index2 < 10; index2++)
        for (Int32 index3 = 0; index3 < 10; index3++)
          ASSERT_EQ(a10(index1, index2, index3), (index1 * 100) + (index2 * 10) + index3);
  }

  TEST(Array, Resize) {
    Array<Int32> a1;
    ASSERT_EQ(a1.Length, 0);
    ASSERT_THROW(a1[-1], ArgumentOutOfRangeException);
    ASSERT_THROW(a1[0], ArgumentOutOfRangeException);

    Array<>::Resize(a1, 1);
    ASSERT_EQ(a1.Length, 1);
    ASSERT_EQ(a1[0], 0);
    ASSERT_THROW(a1[1], ArgumentOutOfRangeException);

    Array<>::Resize(a1, 10);
    ASSERT_EQ(a1.Length, 10);
    ASSERT_EQ(a1[9], 0);
    ASSERT_THROW(a1[10], ArgumentOutOfRangeException);

    Array<>::Resize(a1, 5);
    ASSERT_EQ(a1.Length, 5);
    ASSERT_EQ(a1[4], 0);
    ASSERT_THROW(a1[5], ArgumentOutOfRangeException);

    // No Resize for a multi-dimensional Array
    //Array<string, 2> a2(Int32(0), Int32(0));
    //ASSERT_EQ(a2.Length, 0);
    //ASSERT_THROW((Array<>::Resize(a2, 10)), ArgumentException);

    Int32 a3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Array<Int32> a4(a3, 0);
    ASSERT_THROW(a4[0], ArgumentOutOfRangeException);

    Array<>::Resize(a4, 3);
    ASSERT_EQ(a4.Length, 3);
    ASSERT_EQ(a4[2], 0);
    ASSERT_THROW(a4[4], ArgumentOutOfRangeException);
    Array<>::Resize(a4, 2);
    ASSERT_THROW(a4[2], ArgumentOutOfRangeException);

    Array<>::Resize(a4, 6);
    ASSERT_EQ(a4.Length, 6);
    ASSERT_EQ(a4[5], 0);
    ASSERT_THROW(a4[6], ArgumentOutOfRangeException);

    Array<>::Resize(a4, 10);
    ASSERT_EQ(a4.Length, 10);
  }

  TEST(Array, AssignementOperator) {
    Array<string> a1(5);
    a1[0] = "Tyrannosaurus";
    a1[1] = "Compsognathus";
    a1[2] = "Amargasaurus";
    a1[3] = "Oviraptor";
    a1[4] = "Velociraptor";

    ASSERT_TRUE(a1[0] == "Tyrannosaurus");
    ASSERT_TRUE(a1[1] == "Compsognathus");
    ASSERT_TRUE(a1[2] == "Amargasaurus");
    ASSERT_TRUE(a1[3] == "Oviraptor");
    ASSERT_TRUE(a1[4] == "Velociraptor");

    Array<string> a2(5);
    a2 = a1;
    ASSERT_EQ(a2[0], a1[0]);
    ASSERT_EQ(a2[1], a1[1]);
    ASSERT_EQ(a2[2], a1[2]);
    ASSERT_EQ(a2[3], a1[3]);
    ASSERT_EQ(a2[4], a1[4]);

    Array<string> a3;
    a3 = a2;
    ASSERT_EQ(a3.Length, 5);
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
    ASSERT_EQ(a2[3], a1[0]);
    ASSERT_EQ(a2[4], a1[1]);
    ASSERT_EQ(a2[5], a1[2]);
    ASSERT_EQ(a2[6], a1[3]);
    ASSERT_EQ(a2[7], a1[4]);
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

    ASSERT_EQ(array1[3], string("Test4"));
    ASSERT_EQ(array2[3], string("Test4"));

    Collections::Generic::Enumerator<string> enum1 = array1.GetEnumerator();
    Collections::Generic::Enumerator<string> enum2 = array2.GetEnumerator();
    while (enum1.MoveNext() && enum2.MoveNext())
      ASSERT_EQ(enum1.Current(), enum2.Current());

    array1[3] = "Reset";

    ASSERT_EQ(array1[3], string("Reset"));
    EXPECT_NE(array2[3], string("Reset"));

    Array<>::Resize(array1, 3);
    ASSERT_EQ(array1.Length, 3);
    Array<>::Resize(array1, 6);
    ASSERT_EQ(array1.Length, 6);
  }


  TEST(Array, PolymorphicArray) {
    Array<refptr<Object>> PolymorphicList(50);
    PolymorphicList[0] = ref_new<Int32>(1024);
    PolymorphicList[1] = ref_new<String>("Polymorphic");
    PolymorphicList[2] = ref_new<Boolean>(true);
    PolymorphicList[3] = ref_new<Char>('P');

    ASSERT_TRUE(is<Int32>(*(PolymorphicList[0])));
    ASSERT_TRUE(is<string>(*(PolymorphicList[1])));
    ASSERT_TRUE(is<Boolean>(*(PolymorphicList[2])));
    ASSERT_TRUE(is<Char>(*(PolymorphicList[3])));

    ASSERT_EQ(string("1024"), PolymorphicList[0]->ToString());
    ASSERT_EQ(string("Polymorphic"), PolymorphicList[1]->ToString());
    ASSERT_EQ(string("True"), PolymorphicList[2]->ToString());
    ASSERT_EQ(string("P"), PolymorphicList[3]->ToString());
  }

  TEST(Array, GetEnumerator) {
    Array<int32> array(10);
    for (int32 index = 0; index < 10; index++)
      array[index] = (index + 10) * 2;

    _using(System::Collections::Generic::Enumerator<int32> enumerator = array.GetEnumerator()) {
      int32 index = 0;
      while (enumerator.MoveNext()) {
        ASSERT_EQ((index + 10) * 2, enumerator.Current);
        index++;
      }
    }
  }
}
